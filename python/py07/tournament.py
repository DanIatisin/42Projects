from ex2 import BattleStrategy, InvalidStrategy, NormalStrategy, AggressiveStrategy, DefensiveStrategy
from ex1 import HealingCreatureFactory, TransformingCreatureFactory
from ex0 import CreatureFactory, FlameFactory, AquaFactory
# from ex0.creature import Creature


def battle(opponents: list[tuple[CreatureFactory, BattleStrategy]]) -> None:
    print("*** Tournament ***")
    print(f"{len(opponents)} opponents involved")
    for i in range(len(opponents)):
        for j in range(i + 1, len(opponents)):
            factory_a, strategy_a = opponents[i]
            factory_b, strategy_b = opponents[j]
            creature_a = factory_a.create_base()
            creature_b = factory_b.create_base()
            print()
            print("* Battle *")
            print(creature_a.describe())
            print(" vs.")
            print(creature_b.describe())
            print(" now fight!")
            try:
                strategy_a.act(creature_a)
                strategy_b.act(creature_b)
            except InvalidStrategy as e:
                print(f"Battle error, aborting tournament: {e}")


def main() -> None:
    print("Tournament 0 (basic)")
    print("[(Flameling+Normal), (Healing+Defensive)]")
    battle([(FlameFactory(), NormalStrategy()), 
            (HealingCreatureFactory(), DefensiveStrategy())])
    print()
    print("Tournament 1 (error)")
    print("[(Flameling+Aggresive), (Healing+Defensive)]")
    battle([(FlameFactory(), AggressiveStrategy()),
            (HealingCreatureFactory(), DefensiveStrategy())])
    print()
    print("Tournament 2 (multiple)")
    print("[(Aquabub+Normal), (Healing+Defensive), (Transform+Aggressive)]")
    battle([(AquaFactory(), NormalStrategy()),
            (HealingCreatureFactory(), DefensiveStrategy()),
            (TransformingCreatureFactory(), AggressiveStrategy())])


if __name__ == "__main__":
    main()