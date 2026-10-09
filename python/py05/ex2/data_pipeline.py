from abc import ABC, abstractmethod
from typing import Any, Protocol
import typing


BATCH: list[typing.Any] = [
        "Hello World",
        [3.14, -1, 2.71],
        [{
           "log_level": "WARNING",
           "log_message": "Telnet access! Use ssh instead"
        },
         {
            "log_level": "INFO",
            "log_message": "User wil is connected"
         }],
        42,
        ["Hi", "five"],
    ]


BATCH2: list[typing.Any] = [
        21,
        [
         "I love Ai",
         "LLMs are wonderful",
         "Stay healty",
        ],
        [
            {
                "log_level": "Error",
                "log_message": "500 server crash"
            },
            {
                "log_level": "NOTICE",
                "log_message": "Certificate expires in 10 days",
            }
        ],
        [32, 42, 64, 84, 128, 168],
        "World hello"
    ]


class DataProcessor(ABC):
    def __init__(self) -> None:
        self.pending: list[str] = []
        self.total_processed: int = 0

    @abstractmethod
    def validate(self, data: Any) -> bool:
        pass

    @abstractmethod
    def ingest(self, data: Any) -> None:
        pass

    @abstractmethod
    def get_name(self) -> str:
        pass

    def output(self) -> tuple[int, str]:
        if len(self.pending) == 0:
            raise ValueError("No data to extract")
        rank = self.total_processed - len(self.pending)
        value = self.pending.pop(0)
        return (rank, value)


class NumericProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        if isinstance(data, int | float):
            return True
        if isinstance(data, list):
            if len(data) == 0:
                return False
            for item in data:
                if not isinstance(item, int | float):
                    return False
            return True
        return False

    def ingest(self, data: int | float | list[int | float]) -> None:
        if not self.validate(data):
            raise TypeError("Improper numeric data")
        if not isinstance(data, list):
            items = [data]
        else:
            items = data
        for n in items:
            self.pending.append(str(n))
            self.total_processed += 1

    def get_name(self) -> str:
        return "Numeric Processor"


class TextProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        if isinstance(data, str):
            return True
        if isinstance(data, list):
            for item in data:
                if not isinstance(item, str):
                    return False
            return True
        return False

    def ingest(self, data: str | list[str]) -> None:
        if not self.validate(data):
            raise TypeError("Improper text data")
        if not isinstance(data, list):
            items = [data]
        else:
            items = data
        for s in items:
            self.pending.append(s)
            self.total_processed += 1

    def get_name(self) -> str:
        return "Text Processor"


class LogProcessor(DataProcessor):
    def _is_str_dict(self, d: Any) -> bool:
        if not isinstance(d, dict):
            return False
        for k, v in d.items():
            if not isinstance(k, str) or not isinstance(v, str):
                return False
        return True

    def validate(self, data: Any) -> bool:
        if self._is_str_dict(data):
            return True
        if isinstance(data, list):
            for item in data:
                if not self._is_str_dict(item):
                    return False
            return True
        return False

    def ingest(self, data: dict[str, str] | list[dict[str, str]]) -> None:
        if not self.validate(data):
            raise TypeError("Improper log data")
        if isinstance(data, list):
            items = data
        else:
            items = [data]
        for d in items:
            testo = ": ".join(d.values())
            self.pending.append(testo)
            self.total_processed += 1

    def get_name(self) -> str:
        return "Log Processor"


class ExportPlugin(Protocol):
    def process_output(self, data: list[tuple[int, str]]) -> None:
        pass


class CSVExportPlugin:
    def process_output(self, data: list[tuple[int, str]]) -> None:
        text: list[str] = [t[1] for t in data]
        result: str = ",".join(text)
        print("CSV Output:")
        print(result)


class JSONExportPlugin:
    def process_output(self, data: list[tuple[int, str]]) -> None:
        text: list[str] = [f'"item_{rank}": "{value}"' for rank, value in data]
        result: str = ", ".join(text)
        print("JSON Output:")
        print(f'{"{"}' + result + f'{"}"}')


class DataStream:
    def __init__(self) -> None:
        self.processors: list[DataProcessor] = []

    def register_processor(self, proc: DataProcessor) -> None:
        self.processors.append(proc)

    def process_stream(self, stream: list[typing.Any]) -> None:
        for element in stream:
            flag: bool = False
            for proc in self.processors:
                if proc.validate(element):
                    proc.ingest(element)
                    flag = True
                    break
            if not flag:
                print(
                    "DataStream error - Can't process "
                    f"element in stream: {element}"
                    )

    def output_pipeline(self, nb: int, plugin: ExportPlugin) -> None:
        for proc in self.processors:
            res: list[tuple[int, str]] = []
            for _ in range(nb):
                if len(proc.pending) == 0:
                    break
                res.append(proc.output())
            if res:
                plugin.process_output(res)

    def print_processors_stats(self) -> None:
        print("== DataStream statistics ==")
        if len(self.processors) == 0:
            print("No processor found, no data")
            print()
        else:
            for proc in self.processors:
                print(
                    f"{proc.get_name()}: total {proc.total_processed} "
                    f"items processed, remaining {len(proc.pending)} "
                    "on processor"
                    )


def main() -> None:
    print("=== Code Nexus - Data Stream ===")
    print()
    print("Initialize Data Stream...")
    print()
    data = DataStream()
    data.print_processors_stats()
    numeric = NumericProcessor()
    text = TextProcessor()
    log = LogProcessor()
    csv = CSVExportPlugin()
    json = JSONExportPlugin()
    print("Registering Processors")
    print()
    print(f"Send first batch of data on stream: {BATCH}")
    print()
    data.register_processor(numeric)
    data.register_processor(text)
    data.register_processor(log)
    data.process_stream(BATCH)
    data.print_processors_stats()
    print()
    print("Send 3 processed data from each processor to a CSV Plugin:")
    data.output_pipeline(3, csv)
    print()
    print(f"Send another batch of data: {BATCH2}")
    print()
    data.process_stream(BATCH2)
    data.print_processors_stats()
    print()
    print("Send 5 processed data from each processor to a JSON plugin")
    data.output_pipeline(5, json)
    print()
    data.print_processors_stats()


if __name__ == "__main__":
    main()
