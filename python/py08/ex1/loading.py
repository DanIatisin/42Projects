import importlib.util
from importlib.metadata import version, PackageNotFoundError
import sys


REQUIREMENTS: dict[str, str] = {
        "pandas": "Data manipulation ready",
        "numpy": "Numerical computation ready",
        "matplotlib": "Visualization ready"
}


POINTS: int = 1000


def check_dependencies() -> tuple[dict[str, str], dict[str, str]]:
    errors: dict[str, str] = {}
    installed_packages: dict[str, str] = {}

    for module in REQUIREMENTS:
        spec = importlib.util.find_spec(module)
        if spec is None:
            errors[module] = "module not installed"
        else:
            try:
                installed_packages[module] = version(module)
            except PackageNotFoundError:
                errors[module] = "package not found"
    return errors, installed_packages
 

def display_dependencies() -> bool:
    print("LOADING STATUS: Loading programs...")
    print()
    print("Checking dependencies:")
    errors, installed_packages = check_dependencies()

    all_ok: bool = True
    for module in REQUIREMENTS:
        if module in installed_packages:
            print(f"[OK] {module} ({installed_packages[module]}) "
                  f"- {REQUIREMENTS[module]}")
        else:
            error_msg = errors.get(module, "module not installed")
            print(f"[ERROR] {module} ({error_msg})")
            # sys.exit(f"[ERROR] {module} - module not installed")
            all_ok = False

    return all_ok


def analyze_matrix_data() -> None:
    import numpy as np
    import pandas as pd
    import matplotlib.pyplot as plt

    print()
    data = np.random.randn(POINTS, 2)
    df = pd.DataFrame(data, columns=["Signal_A", "Signal_B"])
    # df = pd.DataFrame({"a": [1, 2], "b": [2, 3]}, index=["A", "B"])
    rows, columns = df.shape
    describe = df.describe()

    print("Analyzing Matrix data...")
    print(f"Processing {rows} data points...")
    print()
    print(describe)
    print()
    print("Generating visualization...")
    plt.figure(figsize=(8, 6))
    plt.plot(df["Signal_A"], df["Signal_B"], 'g.', alpha=0.5)
    plt.title("Matrix Data Analysis")
    plt.xlabel("Signal_A")
    plt.ylabel("Signal_B")
    plt.grid(True)

    output_file = "matrix_analysis.png"
    plt.savefig(output_file)
    plt.close()
    print()
    print("Analysis complete!")
    print(f"Results saved to: {output_file}")


def main() -> None:
    if display_dependencies():
        analyze_matrix_data()
    else:
        print("\n[WARNING] Some required dependencies are missing.")
        print("Please install them using pip or Poetry:")
        print(" pip install -r requirements.txt")
        print("python3 loading.py")
        print("# or")
        print(" poetry install")
        print("poetry run python loading.py")


if __name__ == "__main__":
    main()
