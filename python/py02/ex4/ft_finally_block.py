class GardenError(Exception):
    def __init__(self, message: str = "Uknown garden error") -> None:
        self.message = message
        super().__init__(self.message)


class PlantError(GardenError):
    def __init__(self, message: str = "Uknown plant error") -> None:
        self.message = message
        super().__init__(self.message)


class WaterError(GardenError):
    def __init__(self, message: str = "Unknown plant error") -> None:
        self.message = message
        super().__init__(self.message)


def raise_plant_error() -> None:
    raise PlantError("The tomato plant is wilting!")


def raise_water_error() -> None:
    raise WaterError("Not enough water in the tank!")


def water_plant(plant_name: str) -> None:
    if plant_name == str.capitalize(plant_name):
        print(f"Watering {plant_name}[OK]")
    else:
        raise PlantError(f"invalid plant name to water: '{plant_name}'")


def test_watering_system() -> None:
    print("Testing valid plants...")
    print("Opening watering system")
    try:
        for plant in ("Tomato", "Lettuce", "Carrot"):
            water_plant(plant)
    except PlantError as e:
        print(f"Caught PlantError: {e}")
        print("..ending tests and returning to main")
        return
    finally:
        print("Closing watering system")
    print()
    print("Testing invalid plants...")
    try:
        for plant in ("Tomato", "lettuce", "Carrot"):
            water_plant(plant)
    except PlantError as e:
        print(f"Caught PlantError: {e}")
        print(".. ending tests and returning to main")
        return
    finally:
        print("Closing invalid plants")


if __name__ == "__main__":
    print("=== Garden Watering System ===")
    print()
    test_watering_system()
    print()
    print("Cleanup always happens, even with errors!")
