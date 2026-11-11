from abc import ABC, abstractmethod
from ex0.creature import Creature

class InvalidStrategy(Exception):
    pass


class BattleStategy(ABC):
     @abstractmethod
     def is_valid(self, creature: Creature ) -> bool:
        pass

    @abstractmethod
    def act(self, creature: Creature) -> None:
        pass


class NormalStrategy(BattleStategy):
    def is_valid(self, creature: Creature) -> bool:
        return True

    def act(self, creature: Creature) -> None:
        print(creature.attack())


class AggressiveStrategy(BattleStategy):
    def is_valid(self, creature: Creature) -> bool:
        return isinstance(creature, TransformingCapability)

    def act(self, creature: Creature) -> None:
        if not isinstance(creature, TransformCapability):
            raise InvalidStrategy(
                f"Invalid Creature '{creature.name}' for this aggressive strategy")
        print(creature.transform())
        print(creature.attack())
        print(creature.revert())


class DefensiveStrategy(BattleStategy):
    def is_valid(self, creature: Creature) -> bool:
        return isinstance(creature, HealCapability)

    def act(self, creature: Creature) -> None:
        if not isinstance(creature, HealCapability):
            raise InvalidStrategy(
                f"Invalid Creature '{creature.name}' for this aggressive strategy")
        print(creature.attack())
        print(creature.heal())
