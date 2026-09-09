class Plant():
    def __init__(self, p_name: str, p_height: float, p_age: int) -> None:
        self.p_name = p_name
        self._height = p_height
        self._age = p_age

    def show(self) -> None:
        print(f"{self.p_name}: {round(self._height, 1)}cm, "
              f"{self._age} days old")

    def grow(self) -> None:
        self._height = self._height + 0.8

    def get_age(self) -> int:
        return self._age

    def set_age(self, age) -> None:
        if age < 0:
            print(f"{self.p_name}: Error, age can't be a negative number")
            print("Age update rejected")
        else:
            self._age = age
            print(f"Age updated: {self._age} days")

    def get_height(self) -> float:
        return self._height

    def set_height(self, height) -> None:
        if height < 0:
            print(f"{self.p_name}: Error, height can't be a negative number")
            print("Height update rejected")
        else:
            self._height = height
            print(f"Height updated: {self._height}cm")


if __name__ == "__main__":
    print("=== Garden security ===")

    plant = Plant("Rose", 15.0, 10)
    print("Plant created: ", end="")
    plant.show()
    print()
    plant.set_height(25.0)
    plant.set_age(30)
    print()
    plant.set_height(-20)
    plant.set_age(-50)
    print()
    print("Current state: ", end="")
    plant.show()
