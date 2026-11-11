from ex0 import CreatureFactory, FlameFactory, AquaFactory
from ex0.creature import Creature


def testing_factory(factory: CreatureFactory) -> None:
    creature_base: Creature = factory.create_base()
    creature_evolved: Creature = factory.create_evolved()
    print("Testing factory")
    print(creature_base.describe())
    print(creature_base.attack())
    print(creature_evolved.describe())
    print(creature_evolved.attack())
    print()


def testing_battle(factory1: CreatureFactory, factory2: CreatureFactory) -> None:
    creature1: Creature = factory1.create_base()
    creature2: Creature = factory2.create_base()
    print("Testing battle")
    print(creature1.describe())
    print(" vs")
    print(creature2.describe())
    print(" fight!")
    print(creature1.attack())
    print(creature2.attack())


def main() -> None:
    testing_factory(FlameFactory())
    testing_factory(AquaFactory())
    testing_battle(FlameFactory(), AquaFactory())


if __name__ == "__main__":
    main()