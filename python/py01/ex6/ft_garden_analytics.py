class Plant():

    class _Stats():
        def __init__(self) -> None:
            self._grow_count: int = 0
            self._age_count: int = 0
            self._show_count: int = 0

        def show(self) -> None:
            print(f"Stats: {self._grow_count} grow, "
                  f"{self._age_count} age, {self._show_count} show")

    GROWTH: float = 0.8
    AGE_RATE: int = 1

    def __init__(self, p_name: str, p_height: float, p_age: int) -> None:
        self.p_name = p_name
        self._height: float = 0.0
        self._age: int = 0
        self.set_height(p_height)
        self.set_age(p_age)
        self._stats: Plant._Stats = Plant._Stats()

    def show(self) -> None:
        print(f"{self.p_name}: {round(self._height, 1)}cm, "
              f"{self._age} days old")
        self._stats._show_count += 1

    def grow(self) -> None:
        self.set_height(round(self.get_height() + self.GROWTH, 1))
        self._stats._grow_count += 1

    def age(self) -> None:
        self.set_age(self._age + self.AGE_RATE)
        self._stats._age_count += 1

    def get_age(self) -> int:
        return self._age

    def set_age(self, age: int) -> bool:
        if age < 0:
            print(f"{self.p_name}: Error, age can't be a negative number")
            print("Age update rejected")
            return False
        else:
            self._age = age
            return True

    def get_height(self) -> float:
        return self._height

    def set_height(self, height: float) -> None:
        if height < 0.0:
            print(f"{self.p_name}: Error, height can't be a negative number")
            print("Height update rejected")
        else:
            self._height = height
            # print(f"Height updated: {self._height}cm")

    def show_stats(self) -> None:
        self._stats.show()

    @staticmethod
    def is_years_old(age: int) -> bool:
        if age >= 365:
            return True
        return False

    @classmethod
    def anonymous(cls) -> "Plant":
        return cls("Unknown plant", 0.0, 0)


class Flower(Plant):
    GROWTH: float = 8.0
    AGE_RATE: int = 20

    def __init__(self, name: str, height: float, age: int, color: str) -> None:
        super().__init__(name, height, age)
        self._color = color
        self._bloomed = False

    def show(self) -> None:
        super().show()
        print(f" Color: {self._color}")
        if self._bloomed:
            print(" Rose is blooming beautifully!")
        else:
            print(" Rose has not bloomed yet")

    def bloom(self) -> None:
        self._bloomed = True


class Tree(Plant):
    def __init__(self, name: str, height: float, age: int,
                 trunk_diameter: float) -> None:
        super().__init__(name, height, age)
        self._trunk_diameter = trunk_diameter
        self._shade_count: int = 0

    def produce_shade(self) -> None:
        self._shade_count += 1
        print(f"Tree {self.p_name} now produces shade of "
              f"{self._height}cm long and {self._trunk_diameter} wide.")

    def show(self) -> None:
        super().show()
        print(f" Trunk diameter: {self._trunk_diameter}cm")

    def show_stats(self) -> None:
        super().show()
        print(f" {self._shade_count} shade")


class Vegetable(Plant):
    def __init__(self, name: str, height: float, age: int,
                 harvest_season: str, nutritional_value: int) -> None:
        super().__init__(name, height, age)
        self._harvest_season: str = harvest_season
        self._nutritional_value: int = nutritional_value

    def show(self) -> None:
        super().show()
        print(f"Harvest season: {self._harvest_season}")
        print(f"Nutritional value: {self._nutritional_value}")

    def age(self) -> None:
        super().age()

    def grow(self) -> None:
        super().grow()
        self.grow_bonus()

    def grow_bonus(self) -> None:
        self.set_height(round(self.get_height() + 1.3, 1))
        self._nutritional_value += 1


class Seed(Flower):
    GROWTH: float = 30.0

    def __init__(self, name: str, height: float, age: int, color: str) -> None:
        super().__init__(name, height, age, color)
        self._seeds: int = 0

    def bloom(self) -> None:
        super().bloom()
        self._seeds = 42

    def show(self) -> None:
        super().show()
        print(f" Seeds: {self._seeds}")


def display_statistics(plant: Plant) -> None:
    plant.show_stats()


if __name__ == "__main__":
    print("=== Garden Statistics ===")
    print("=== Check year-old")
    print(f"Is 30 days more than a year? -> {Plant.is_years_old(30)}")
    print(f"Is 400 days more than a year? -> {Plant.is_years_old(400)}")
    print()
    print("=== Flower")
    rose: Flower = Flower("Rose", 15.0, 10, "red")
    rose.show()
    print("[statistics for Rose]")
    display_statistics(rose)
    print("[asking rose to grow and bloom]")
    rose.bloom()
    rose.grow()
    rose.show()
    print("[statisitcs for Rose]")
    display_statistics(rose)
    print()
    print("=== Tree")
    oak: Tree = Tree("Oak", 200.0, 365, 5.0)
    oak.show()
    print("[statistics for Oak]")
    display_statistics(oak)
    print("[asking the oak to produce shade]")
    oak.produce_shade()
    print("[statistics for Oak]")
    display_statistics(oak)
    print()
    print("=== Seed")
    sunflower: Seed = Seed("Sunflower", 80.0, 45, "yellow")
    sunflower.show()
    print("[make sunflower grow, age and bloom]")
    sunflower.grow()
    sunflower.age()
    sunflower.bloom()
    sunflower.show()
    print("[statistics for Sunflower]")
    display_statistics(sunflower)
    print()
    print("=== Anonymous")
    unknown: Plant = Plant.anonymous()
    unknown.show()
    print("[statistics for Unknown plant]")
    display_statistics(unknown)
