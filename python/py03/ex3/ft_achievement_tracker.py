import random


ACHIEVEMENTS: list[str] = ["Crafting Genius", "World Savior",
                           "Master Explorer", "Collector Supreme",
                           "Untouchable", "Boss Slayer", "Strategist",
                           "Unstopable", "Speed Runner", "Survivor",
                           "Treasure Hunter", "First Steps", "Sharp Mind",
                           "Hidden Path Finder"]


def get_player_achievement() -> set[str]:
    n = random.randint(4, 9)
    return set(random.sample(ACHIEVEMENTS, n))


def only_has(player: set[str],
             other1: set[str],
             other2: set[str],
             other3: set[str]
             ) -> set[str]:
    return player.difference(other1.union(other2, other3))


def is_missing(player: set[str]) -> set[str]:
    all_achievements: set[str] = set(ACHIEVEMENTS)
    return (all_achievements.difference(player))


def main() -> None:
    alice = get_player_achievement()
    bob = get_player_achievement()
    charlie = get_player_achievement()
    dylan = get_player_achievement()

    print(f"Player Alice: {alice}")
    print(f"Player Bob: {bob}")
    print(f"Player Charlie: {charlie}")
    print(f"Player Dylan: {dylan}")
    print()

    distint = alice.union(bob, charlie, dylan)
    print(f"All distinct achievements: {distint}")
    print()

    common = alice.intersection(bob, charlie, dylan)
    print(f"Common achievements: {common}")
    print()

    print(f"Only Alice has: {alice.difference(bob, charlie, dylan)}")
    print(f"Only Bob has: {bob.difference(alice, charlie, dylan)}")
    print(f"Only Charlie has: {charlie.difference(alice, bob, dylan)}")
    print(f"Only Dylan has: {dylan.difference(alice, bob, charlie)}")
    print()

    print(f"Only Alice is missing: {is_missing(alice)}")
    print(f"Only Bob is missing: {is_missing(bob)}")
    print(f"Only Charlie is missing: {is_missing(charlie)}")
    print(f"Only Dylan is missing: {is_missing(dylan)}")


if __name__ == "__main__":
    print("=== Achievement Tracker System ===")
    print()
    main()
