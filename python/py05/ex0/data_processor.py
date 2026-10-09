from abc import ABC, abstractmethod
from typing import Any


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


def print_numeric() -> None:
    print("Testing Numeric Processor...")
    proc = NumericProcessor()
    print(
        "Trying to validate input '42': "
        f"{proc.validate(42)}"
        )
    print(
        "Trying to validate input 'Hello': "
        f"{proc.validate('Hello')}"
        )
    print(
        "Test invalid ingestion of string "
        "'foo' without prior validation:"
        )
    try:
        proc.ingest("foo")
    except TypeError as e:
        print(f"Got exception: {e}")
    data: list[int | float] = [1, 2, 3, 4, 5]
    print(f"Processing data: {data}")
    proc.ingest(data)
    print("Extracting 3 values...")
    for _ in range(3):
        rank, value = proc.output()
        print(f"Numeric value {rank}: {value}")


def print_text() -> None:
    print("Testing Text Processor...")
    proc = TextProcessor()
    print(
        "Trying to validate input '42': "
        f"{proc.validate(42)}"
        )
    data: list[str] = ["Hello", "Nexus", "World"]
    print(f"Processing data: {data}")
    proc.ingest(data)
    print("Extracting 1 value...")
    for _ in range(1):
        rank, value = proc.output()
        print(f"Text value {rank}: {value}")


def print_logs() -> None:
    print("Testing Log Processor...")
    proc = LogProcessor()
    print(f"Trying to validate input 'Hello': {proc.validate('Hello')}")
    data: list[dict] = [
        {
         "log_level": "NOTICE",
         "log_message": "Connection to server"
        },
        {
         "log_level": "ERROR",
         "log_message": "Unauthorized access!!"
        }
        ]
    print(f"Processing data: {data}")
    proc.ingest(data)
    print("Extracting 2 values...")
    for _ in range(2):
        rank, value = proc.output()
        print(f"Log entry {rank}: {value}")


def main() -> None:
    print("=== Code Nexus - Data Processor ===")
    print()
    print_numeric()
    print()
    print_text()
    print()
    print_logs()


if __name__ == "__main__":
    main()
