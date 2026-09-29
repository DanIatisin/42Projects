def ft_count_harvest_iterative() -> None:
    n = int(input("Days until harvest: "))
    for day in range(1, n + 1):
        print(f"Day {day}")
    print("Harvest time!")
