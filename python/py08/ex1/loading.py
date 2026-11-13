import importlib.util
from importlib.metadata import version, PackageNotFoundError


REQUIREMENTS: dict[str, str] = {
        "pandas": "Data manipulation ready",
        "numpy": "Numerical computation ready",
        "matplotlib": "Visualization ready"
}


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
 

def diplay_dependencies() -> bool:
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
            all_ok = False

    return all_ok


def analyze_matrix_data() -> None:
    import numpy as np
    import pandas as pd
    import matplotlib.pyplot as plt

    print()
    print("Analyzing Matrix data...")
    print("Processing 1000 data points...")

    data = np.random.randn(1000, 2)
    df = pd.DataFrame(data, columns=["Signal_A", "Signal_B"])

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
    if diplay_dependencies():
        analyze_matrix_data()
    else:
        print("\n[WARNING] Some required dependencies are missing.")
        print("Please install them using pip or Poetry:")
        print(" pip install -r requirements.txt")
        print("# or")
        print(" poetry install")


if __name__ == "__main__":
    main()
