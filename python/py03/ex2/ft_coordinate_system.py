import math


def get_player_pos() -> tuple[float, float, float]:
    PROMPT: str = "Enter new coordinates as floats in format 'x,y,z': "
    while True:
        user_input: str = input(PROMPT)
        parts: list[str] = user_input.split(",")
        if len(parts) != 3:
            print("Invalid syntax")
            continue
        try:
            coords: list[float] = []
            for arg in parts:
                coords.append(float(arg))
        except ValueError as e:
            print(f"Error on parameter '{arg}': {e}")
            continue
        return tuple(coords)


def main() -> None:
    print("Get a first set of coordinates")
    first_pos: tuple[float] = get_player_pos()
    print(f"Got a first tuple: {first_pos}")
    print(f"It includes: X={first_pos[0]},"
          f"Y={first_pos[1]}, Z={first_pos[2]}")
    distance_center: float = math.sqrt(
                first_pos[0]**2 +
                first_pos[1]**2 +
                first_pos[2]**2)
    print(f"Distance to center: {round(distance_center, 4)}")
    print()
    print("Get a second set of coordinates")
    second_pos: tuple[float] = get_player_pos()
    distance_points: float = math.sqrt(
                (first_pos[0] - second_pos[0])**2 +
                (first_pos[1] - second_pos[1])**2 +
                (first_pos[2] - second_pos[2])**2)
    print(f"Distance between the 2 sets of coordinates: {round(distance_points, 4)}")


if __name__ == "__main__":
    main()