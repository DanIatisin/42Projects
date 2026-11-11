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


def testing_battle(flame_factory: CreatureFactory,
                   aqua_factory: CreatureFactory) -> None:
    flame_creature: Creature = flame_factory.create_base()
    aqua_creature: Creature = aqua_factory.create_base()
    print("Testing battle")
    print(flame_creature.describe())
    print(" vs")
    print(aqua_creature.describe())
    print(" fight!")
    print(flame_creature.attack())
    print(aqua_creature.attack())


def main() -> None:
    testing_factory(FlameFactory())
    testing_factory(AquaFactory())
    testing_battle(FlameFactory(), AquaFactory())


if __name__ == "__main__":
    main()
