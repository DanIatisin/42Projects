import sys
import typing


def read_archive(name: str) -> None:
    try:
        f = open(name, "r")
    except OSError as e:
        print(f"Error opening file '{name}': {e}")
        return
    try:
        content = f.read()
        print(f"{content}")
    except (OSError, UnicodeDecodeError):
        print(f"Error reading file '{name}': {e}")
        return
    finally:
        f.close()
        print()
        print("---")
        print(f"File '{name}' closed")


def main() -> None: 
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} <file>")
        return
    print("=== Cyber Archives Recovery ===")
    print(f"Accessing file {sys.argv[1]}")
    print("---")
    print("")
    read_archive(sys.argv[1])

if __name__ == "__main__":
    main()