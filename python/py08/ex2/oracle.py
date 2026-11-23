from dotenv import load_dotenv
import os
import sys


load_dotenv()
MANDATORY: dict[str, dict[str, str | None]] = {
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


def check_config() -> None:
    mode: str | None = os.getenv('MATRIX_MODE')
    errors: list[str] = []
    if mode is None:
        sys.exit("The Mode variable is missing or is misspelled")
    mode = mode.strip()
    if mode == "":
        sys.exit("The value of mode variable is not present")
    mode = mode.lower()
    if mode not in ("development", "production"):
        sys.exit("The mode value is not valid. Please use: "
                 "'production' or 'development'")
    print(f"Mode: {mode}")
    for name, info in MANDATORY.items():
        alt_name: str | None = info['label']
        msg_show: str | None = info['shown']
        value: str | None = os.getenv(name)
        if value is None:
            if mode == "development":
                print(f"The variable {name} is missing or misspelled / "
                      "please add the requested variable in .env")
            else:
                errors.append(f"Missing or misspelled variable {name} / "
                             "please add the requested variable in .env")
            continue
        value = value.strip()
        if value == "":
            if mode == "development":
                print(f"The variable {name} has no value /"
                      "add a value to the varible in .env file")
            else:
                errors.append(f"The variable {name} has no value /"
                              "add a value to the varible in .env file")
            continue
        if msg_show is not None:
            print(f"{alt_name}: {msg_show}")
        else:
            print(f"{alt_name}: {os.getenv(name)}")
    if errors:
        print()
        for msg in errors:
            print(msg)
        sys.exit("Erros found!")


def check_env_security() -> None:
    pass


def main() -> None:
   check_config()
   print("Pass")


if __name__ == "__main__":
    main()
