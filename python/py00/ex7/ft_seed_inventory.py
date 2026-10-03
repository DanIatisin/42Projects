def ft_seed_inventory(seed_type: str, quantity: int, unit: str) -> None:
    s_type = seed_type.capitalize()

    if unit == "packets":
        print(f"{s_type} seeds: {quantity} {unit} available")
    elif unit == "grams":
        print(f"{s_type} seeds: {quantity} {unit} total")
    elif unit == "area":
        print(f"{s_type} seeds: covers {quantity} square meters")
    else:
        print("Unknown unit type")
