from dotenv import load_dotenv
import os


load_dotenv()
ETIQ: dict[str, dict[str, str | None]] = {
                "MATRIX_MODE": {"label": "Mode", "shown": None,
                                "default": "development"},
                "DATABASE_URL": {"label": "Database",
                                 "shown": "Connected to local instance",
                                 "default": None},
                "API_KEY": {"label": "API Access", "shown": "Authenticated",
                            "default": None},
                "LOG_LEVEL": {"label": "Log Level", "shown": None,
                              "default": "INFO"},
                "ZION_ENDPOINT": {"label": "Zion Network", "shown": "Online",
                                  "default": None}
                }


def main() -> None:
    for name, info in ETIQ.items():
        alt_name: str | None = info['label']
        msg_show: str | None = info['shown']
        value: str | None = os.getenv(name)
        if os.getenv(name) is None:
            print(f"The key is missing: {name}")
            print("Add the missing key with its value in your .env file")
        elif (value == "" and info['default'] is None):
            print(f"The value for key {name} is missing")
            print("Add the value to its corresponding key in your .env file")
        elif (value == "" and info['default'] is not None):
            print(f"{alt_name}: {info['default']}")
        elif msg_show is None:
            print(f"{alt_name}: {value}")
        else:
            print(f"{alt_name}: {msg_show}")


if __name__ == "__main__":
    main()
