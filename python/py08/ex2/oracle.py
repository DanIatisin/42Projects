from dotenv import load_dotenv
import os


load_dotenv()
MANDATORY: dict[str, dict[str, str | None]] = {
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
        for name, info in MANDATORY.items():
            alt_name: str | None = info['label']
            msg_show: str | None = info['shown']
            value: str | None = os.getenv(name)
            if value is None:
                print(f"Missing or misspelled variable name for: {name}"
                    " / please add the variable in .env")
            elif value == "":
                if info['default'] is None:
                    print(f"The value is missing for {name}"
                        " / add the value to the variable in .env")
                else:
                    print(f"{alt_name}: {info['default']} / using default value")
            elif msg_show is not None:
                print(f"{alt_name}: {msg_show}")
            else:
                print(f"{alt_name}: {value}")


if __name__ == "__main__":
    main()
