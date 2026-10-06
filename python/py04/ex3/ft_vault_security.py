SUCCESS: str = "Content successfully written to file"


def secure_archive(
    name: str,
    action: str = "read",
    content: str = ""
) -> tuple[bool, str]:
    try:
        if action == "read":
            with open(name, "r") as f:
                data = f.read()
            return (True, data)
        if action == "write":
            with open(name, "w") as f:
                f.write(content)
            return (True, SUCCESS)
        return (False, "...")
    except (OSError, UnicodeDecodeError) as e:
        return (False, str(e))


def main() -> None:
    content: str = "Hello World 42"
    print("=== Cyber Archives Security ===\n")
    print("Using 'secure_archive' to read from a nonexistent file:")
    print(f"{secure_archive("/not/existing/file")}\n")
    print("Using 'secure_archive' to read from an inaccessible file:")
    print(f"{secure_archive("/etc/shadow")}\n")
    print("Using 'secure_archive' to read from a regular file:")
    print(f"{secure_archive("file.txt")}\n")
    print("Using 'secure_archive' to read from a regular file:")
    print(f"{secure_archive("file2.txt", "write", content)}")


if __name__ == "__main__":
    main()
