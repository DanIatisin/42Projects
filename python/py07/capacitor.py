from ex1 import HealingCreatureFactory, TransformingCreatureFactory
from ex0 import CreatureFactory


def testing_healFactory(heal_creature: CreatureFactory) -> None:
    base_creature = heal_creature.create_base()
    evo_creature = heal_creature.create_evolved()
    print("Testing Creature with healing capability")
    print(" base:")
    print(base_creature.describe())
    print(base_creature.attack())
    print(base_creature.heal())
    print(" evolved:")
    print(evo_creature.describe())
    print(evo_creature.attack())
    print(evo_creature.heal())


def testing_transformingFactory(transform_creature: CreatureFactory) -> None:
    base_creature = transform_creature.create_base()
    evo_creature = transform_creature.create_evolved()
    print("Testing Creature with transform capability")
    print(" base:")
    print(base_creature.describe())
    print(base_creature.attack())
    print(base_creature.transform())
    print(base_creature.attack())
    print(base_creature.revert())
    print(" evolved:")
    print(evo_creature.describe())
    print(evo_creature.attack())
    print(evo_creature.transform())
    print(evo_creature.attack())
    print(evo_creature.revert())


def main() -> None:
    testing_healFactory(HealingCreatureFactory())
    print()
    testing_transformingFactory(TransformingCreatureFactory())


if __name__ == "__main__":
    main()
