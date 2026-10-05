import sys
import typing


def catch_error(name: str) -> typing.IO[str]:
    try:
        f: typing.IO[str] = open(name, "r")
    except FileNotFoundError as e:
        print(f"Error opening file '{name}': {e}")
        return
    except PermissionError as e:
        print(f"Error opening file '{name}': {e}")
        return
    except OSError as e:
        print(f"Erro opening file '{name}': {e}")
        return
    return f


def main() -> None:
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} <file>")
        return
    name: str = sys.argv[1]
    content: str = catch_error(name)
    if content == None:
        return
    
    print (f"{content}")


if __name__ == "__main__":
    main()