def ft_count_harvest_recursive() -> None:
    n = int(input("Days until harvest: "))
    count_days(n, 1)


def count_days(n: int, day: int) -> None:
    if day > n:
        print("Harvest time!")
        return
    print(f"Day {day}")
    count_days(n, day + 1)
