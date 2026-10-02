import sys


def show_data() -> None:
    n: int = len(sys.argv)
    i: int = 1
    print(f"Program name: {sys.argv[0]}")
    if n == 1:
        print("No arguments provided!")
    else:
        print(f"Arguments received: {n - 1}")
        while i < n:
            print(f"Argument {i}: {sys.argv[i]}")
            i += 1
    print(f"Total arguments: {n}")


if __name__ == "__main__":
    print("=== Command Quest ===")
    show_data()
