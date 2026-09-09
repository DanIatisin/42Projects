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
    
    def age(self) -> None:
        self._age = set_age + 1

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


class Flower(Plant):
    def __init__(self, name: str, height: float, age: int, color: str) -> None:
        super().__init__(name, height, age)
        self._color = color
        self._bloomed = False

    def show(self) -> None:
        super().show()
        print(f"Color: {self._color}")
        if self._bloomed:
            print("Rose is blooming beautifully!")
        else:
            print("Rose has not bloomed yet")

    def bloom(self) -> None:
        self._bloomed = True


class Tree(Plant):
    def __init__(self, name: str, height: float, age: int,
                 trunk_diameter: float) -> None:
        super().__init__(name, height, age)
        self._trunk_diameter = trunk_diameter

    def show(self) -> None:
        super().show()
        print(f"Trunk diameter: {self._trunk_diameter}cm")

    def shade(self) -> None:
        print(f"Tree {self.p_name} now produces shade of "
              f"{self._height}cm long and {self._trunk_diameter} wide.")


class Vegetable(Plant):
    def __init__(self, name: str, height: float, age: int,
                    harvest_season: str, nutritional_value: int) -> None: 
        super().__init__(name, height, age)
        self._harvest_season = harvest_season
        self._nutritional_value = nutritional_value

    def show(self) -> None:
        super().show()
        print(f"Harvest season: {self._harvest_season}"
                f"Nutritional value: {self._nutritional_value}")

    def grow(self) -> None:
        super().grow()
        self.set_height(round(self.get_height() + 1.3, 1))
        self._nutritional_value += 1

if __name__ == "__main__":
    print("=== Plant Types ===")

    print("=== Flower")
    rose: Flower = Flower("Rose", 15.0, 10, "red")
    rose.show()
    print("[asking rose to bloom]")
    rose.bloom()
    rose.show()
    print()
    print("=== Tree")
    oak: Tree = Tree("Oak", 200.0, 365, 5.0)
    oak.show()
    print("[asking the oak to produce shade]")
    oak.shade()
    print()
    print("=== Vegetable")
    tomato: Vegetable = Vegetable("Tomato", 5.0, 10, "April", 0)
    tomato.show()
    print("[make tomato grow for 20 days]")
    for day in range(1, 21):
        tomato.grow()
    tomato.show()
