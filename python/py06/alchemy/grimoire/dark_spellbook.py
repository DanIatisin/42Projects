from .dark_validator import validate_ingredients


def dark_spell_allowed_ingredients() -> list[str]:
    return ["bast", "frogs", "arsenic", "eyeball"]


def dark_spell_record(spell_name: str, ingredients: str) -> str:
    status: str = validate_ingredients(ingredients)
    if status.endswith("- VALID"):
        return (f"Spell recorded: {spell_name} ({status})")
    elif status.endswith("INVALID"):
        return (f"Spell rejected: {spell_name} ({status})")