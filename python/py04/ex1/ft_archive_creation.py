import sys


def read_archive(name: str) -> str | None:
    try:
        f = open(name, "r")
    except OSError as e:
        print(f"Error opening file '{name}': {e}")
        return None
    try:
        content: str = f.read()
        print(content)
    except (OSError, UnicodeDecodeError) as e:
        print(f"Error reading file '{name}': {e}")
        return None
    finally:
        f.close()
        print()
        print("---")
        print(f"File '{name}' closed")
        print()
    return content


def add_hash(text: str) -> str:
    result: str = text.replace("\n", "#\n")
    if text and not text.endswith("\0"):
        result = result + "#"
    return result


def save_archive(name: str, text: str) -> None:
    print(f"Saving data to '{name}'")
    try:
        f = open(name, "w")
    except OSError as e:
        print(f"Error opening file '{name}': {e}")
        return
    try:
        f.write(text)
        print(f"Data saved in file '{name}'.")
    except OSError as e:
        print(f"Error writing file '{name}' as {e}")
        return
    finally:
        f.close()


def main() -> None:
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} <file>")
        return
    print("=== Cyber Archives Recovery ===")
    print(f"Accessing file {sys.argv[1]}")
    print("---")
    print()
    content: str | None = read_archive(sys.argv[1])
    if content is None:
        return
    print("Transforming data:")
    print("---")
    print()
    new_content: str = add_hash(content)
    print(new_content)
    print()
    print("---")
    new_name: str = input("Enter new file name (or empty): ")
    if new_name == "":
        print("Not saving data.")
        return
    save_archive(new_name, new_content)


if __name__ == "__main__":
    main()
