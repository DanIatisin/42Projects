import importlib.util
from importlib.metadata import version
import pandas
import numpy


REQUIREMENTS: dict[str, None] = {
        "numpy": None,
        "pandas": None,
        "matplot": None
}

def check_dependecies() -> dict[str, str]:
    errors: dict[str, str] = {}
    installed_packages: dict[str, str] = {}

    for module in REQUIREMENTS:
        spec = importlib.util.find_spec(module)

        if spec is None:
            print(f"Missing module: {module}")
            errors[module] = " module not installed"
        else:
            installed_packages[module] = version(module)

    return errors, installed_packages
        


    def main() -> None:
        errors, installed_packages = check_dependecies()

        


    if __name__ == "__main__":
        main()