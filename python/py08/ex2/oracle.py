from dotenv import load_dotenv, dotenv_values, find_dotenv
import os
import sys


CONFIG_KEYS: list[str] = [
    "MATRIX_MODE",
    "DATABASE_URL",
    "API_KEY",
    "LOG_LEVEL",
    "ZION_ENDPOINT"
]


SECRET_KEYS: list[str] = [
    "API_KEY",
    "DATABASE_URL"
]


DEFAULTS: dict[str, str] = {
    "MATRIX_MODE": "development",
    "LOG_LEVEL": "DEBUG"
}


ENV_PATH: str = find_dotenv()


def load_config() -> dict[str, str]:
    load_dotenv(ENV_PATH)
    config: dict[str, str] = {}

    for key in CONFIG_KEYS:
        config[key] = os.environ.get(key, DEFAULTS.get(key, ""))
    return config


def check_gitignore() -> None:
    try:
        with open(".gitignore", "r") as ign:
            content = ign.read()
            if ".env" not in content:
                sys.exit("The .env file is visible")
    except OSError:
        print(".gitignore file does not existst")


def show(config: dict[str, str]) -> None:
    production: bool = config["MATRIX_MODE"].lower() == "production"

    if config["MATRIX_MODE"].lower() not in ("development", "production"):
        sys.exit("The mode can only be delopment or production")
    print(f"Mode: {config['MATRIX_MODE']}")
    print(f"Database: {'Connected' if config['DATABASE_URL'] else 'Offline'}")
    api: str = "Authenticated" if config['API_KEY'] else 'Failed'
    zion: str = "Online" if config['ZION_ENDPOINT'] else "Offline"
    print(f"Api access: {api}")
    print(f"Log Level: {config['LOG_LEVEL']}")
    print(f"Zion Network: {zion}")

    if production:
        print("All keys are mandatory, if missing the program will "
              "abort the run")
    else:
        print("Missing keys are tolerated and reported below")


def check_secret(config: dict[str, str]) -> list[str]:
    try:
        with open(__file__, "r") as file:
            content: str = file.read()
    except OSError:
        return []
    return [
        key for key in SECRET_KEYS
        if config[key] and config[key] in content
    ]


def security_check(config: dict[str, str]) -> None:
    env_values: dict[str, str | None] = dotenv_values(ENV_PATH)
    override: list[str] = [
        key for key, value in env_values.items()
        if key in os.environ and os.getenv(key) != value
    ]
    env_keys: list[str] = [
        key for key in CONFIG_KEYS if key in env_values.keys()
        ]

    secret: list[str] = check_secret(config)

    print("Environment security check:")
    if secret:
        print("[FAIL] secrets are exposed")
    else:
        print("[OK] No hardcoded secrets detected")
    if config["MATRIX_MODE"] == "production":
        print("[OK] .env file not required in production")
    else:
        if env_values:
            if len(env_keys) == len(CONFIG_KEYS):
                print("[OK] .env file properly configured")
            else:
                print("[FAIL] bad .env file configuration")
        else:
            print("[FAIL] no .env file detected")
    print(f"[OK]Production override available, {len(override)} "
          "active changes")

    for key in CONFIG_KEYS:
        if key not in os.environ:
            print(f"[WARNING] Missing key: {key}")


def main() -> None:
    print("ORACLE STATUS: Reading the Matrix...")
    print()
    config: dict[str, str] = load_config()
    check_gitignore()
    print("Configuration loaded:")
    show(config)

    absent: list[str] = [key for key in CONFIG_KEYS if key not in os.environ]
    if config["MATRIX_MODE"] == "production" and absent:
        sys.exit("\nAborting run: "
                 f"\nMissing keys: {absent}")

    print()
    security_check(config)
    print()
    print("The Oracle sees all configuration")


if __name__ == "__main__":
    main()
