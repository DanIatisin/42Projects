from alchemy.potions import healling_potion, strength_potion


def main () -> None:
    print("=== Distilation 0 ===")
    print("Direct access to alchemy/potion.py")
    print(f"Testing strength_potion: {strength_potion()}")
    print(f"Testing healling_potion: {healling_potion()}")


if __name__ == "__main__":
    main()