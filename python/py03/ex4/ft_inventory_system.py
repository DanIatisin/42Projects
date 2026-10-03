import sys


def calc_percentage(inventory: dict[str, int]) -> None:
    total: int = sum(inventory.values())
    for name in inventory.keys():
        try:
            percentage: float = round((inventory[name] / total) * 100, 1)
        except ZeroDivisionError as e:
            print(f"Error divison by zero: {e}")
        continue
        print(f"Item {name} represents {percentage}%")


def get_max(inventory: dict[str, int]) -> None:
    keys = list(inventory.keys())
    most_name = keys[0]
    for name in keys:
        if inventory[name] > inventory[most_name]:
            most_name = name
    print(f"Item most abundant: {most_name} "
          f"with quantity {inventory[most_name]}")


def get_min(inventory: dict[str, int]) -> None:
    keys = list(inventory.keys())
    least_name = keys[0]
    for name in keys:
        if inventory[name] < inventory[least_name]:
            least_name = name
    print(f"Item least abundant: {least_name} "
          f"with quantity {inventory[least_name]}")


def parse_inventory(args: list[str]) -> dict[str, int]:
    inventory: dict[str, int] = {}
    for arg in args:
        parts: list[str] = arg.split(":")
        if len(parts) != 2 or parts[0] == "":
            print(f"Error - invalid parameter '{arg}'")
            continue
        name = parts[0]
        if name in inventory.keys():
            print(f"Redundant item '{name}' - discarding")
            continue
        try:
            inventory[name] = int(parts[1])
        except ValueError as e:
            print(f"Quantity error for '{name}': {e}")
    return inventory


def main() -> None:
    print("=== Inventory System Analysis ===")
    inventory: dict[str, int] = parse_inventory(sys.argv[1:])
    if len(inventory) == 0:
        print("Error - no valid items provided")
        return
    print(f"Got inventory: {inventory}")
    print(f"Item list: {list(inventory.keys())}")
    print(f"Total quantity of the {len(inventory)} "
          f"items: {sum(inventory.values())}")
    calc_percentage(inventory)
    get_max(inventory)
    get_min(inventory)
    inventory.update({"magic_item": 1})
    print(f"Updated inventory: {inventory}")


if __name__ == "__main__":
    main()
