import alchemy.grimoire as light_spell


def main() -> None:
    print("=== Kaboom 0 ===")
    print("Using grimoire module directory")
    print(
    "Testing record light spell: "
    f"{light_spell.light_spell_record('Fantasy', 'air, poison, volcanic')}"
    )


if __name__ == "__main__":
    main()
