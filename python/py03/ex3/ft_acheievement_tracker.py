import random


ACHIEVEMENTS: list[str] = ["Crafting Genius", "World Savior", "Master Esplorer",
                           "Collector Supreme", "Untouchable", "Boss Slayer",
                           "Strategist", "Unstopable", "Speed Runner", "Survivor",
                           "Treasure Hunter", "First Steps", "Sharp Mind",
                           "Hidden Path Finder"]

                
PLAYER_NAMES = ("Alice, Bob, Charlye, Dylan")


def get_player_achievement() -> set[str]:
    n = random.randint(4, 9)
    return set(random.sample(ACHIEVEMENTS, n))


def only_has(player: set[str],
            other1: set[str],
            other2: set[str],
            other3: set[str]
            ) -> set[str]:
            return player.difference(other1.union(other2, other3))


def main() -> None:
    # alice = get_player_achievement()
    # bob = get_player_achievement()
    # charlie = get_player_achievement()
    # dylan = get_player_achievement()
    
    print(f"Player Alice: {alice}"
          f"Player Bob: {bob}"
          f"Player Charlie: {charlie}"
          f"Player Dylan: {dylan}")
    distint = alice.union(bob, charlie, dylan)
    print(f"All distint achievements: {distint}")
    common = alice.intersection(bob, charlie, dylan)
    print(f"Common achievemnts: {common}")



if __name__ == "__main__":
    print("=== Achievement Tracker System ===")
    print()
    main()