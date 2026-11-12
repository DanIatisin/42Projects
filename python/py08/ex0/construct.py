import sys
import os
import site

def detect() -> None:
    if sys.prefix == sys.base_prefix:
        print("MATRIX STATUS: You're still plugged in")
        print(f"Current Python: {sys.executable}")
        print(f"Virtual Environment: ${VIRTUAL_ENV}")
    else:
        print("MATRIX STATUS: Welcome to the construct")
        print(f"Current Python: {sys.executable}")
        print(f"Virtual Environment: {VIRTUAL_ENV}")


def main() -> None:
    detect()


if __name__ == "__main__":
    main()
