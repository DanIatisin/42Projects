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


def test_custom_errors() -> None:
    print("Testing PlanError...")
    try:
        raise_plant_error()
    except PlantError as e:
        print(f"Caught PlantError: {e}")
    print()
    print("Testing WaterError...")
    try:
        raise_water_error()
    except WaterError as e:
        print(f"Caught WaterError: {e}")
    print()
    print("Testing catching all garden errors...")
    for func in (raise_plant_error, raise_water_error):
        try:
            func()
        except GardenError as e:
            print(f"Caught GardenError: {e}")


if __name__ == "__main__":
    print("=== Custom Garden Errors Demo ===")
    print()
    test_custom_errors()
    print()
    print("All custom error types work correctly!")
