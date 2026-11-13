import sys
import os
import site

def detect() -> None:
    if sys.prefix == sys.base_prefix:
        print("MATRIX STATUS: You're still plugged in")
        print()
        print(f"Current Python: {sys.executable}")
        print(f"Virtual Environment: {os.environ.get('VIRTUAL_ENV')} detected")
        print()
        print("WARNING: You're in the global enironment !\n"
              "The machine can see everything you install.")
        print()
        print("To enter the construct, run:")
        print("python -m venv matrix_env")
        print("source matrix_env/bin/activate # On Unix")
        print("matrix_env/Scripts/activate # On Windows")
        print()
        print("Then run this program again.")
    else:
        print("MATRIX STATUS: Welcome to the construct")
        print()
        print(f"Current Python: {sys.executable}")
        print(f"Virtual Environment: {os.environ.get('VIRTUAL_ENV')}")
        print()
        print("SUCCESS: You're in an isolated environment!\n"
              "Safe to install packages without affecting\n"
              "the global system")
        print()
        print("Package instalation path:")
        print(site.getusersitepackages())


def main() -> None:
    detect()


if __name__ == "__main__":
    main()
