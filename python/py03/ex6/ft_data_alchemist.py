import random


PLAYER_NAMES: list[str] = ["Alice", "bob", "Charlie",
                           "Emma", "Gregory", "john",
                           "kevin", "Liam"]


def gen_lists() -> None:
    print("=== Game Data Alchemist ===")
    print()
    first_list: list[str] = [name for name in PLAYER_NAMES]
    print(f"Initial list of players: {first_list}")
    second_list: list[str] = [str.capitalize(name) for name in PLAYER_NAMES]
    print(f"New list with all names capitalized: {second_list}")
    third_list: list[str] = [name for name in PLAYER_NAMES
                             if name == str.capitalize(name)]
    print(f"New list of capitalized names only: {third_list}")
    print()
    add_score: dict[str, int] = {name: random.randint(100, 800)
                                 for name in second_list}
    print(f"Score dict: {add_score}")
    total: int = sum([add_score[name] for name in add_score])
    average: float = round(total / len(add_score), 2)
    print(f"Score average is {average}")
    high_scores: dict[str, int] = {name: add_score[name] for name in add_score
                                   if add_score[name] > average}
    print(f"High scores: {high_scores}")


if __name__ == "__main__":
    gen_lists()
