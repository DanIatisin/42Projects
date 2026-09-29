def input_temperature(temp_str: str) -> int:
    temp = int(temp_str)
    if temp > 40:
        raise ValueError(f"{temp} is too hot for plants (max 40°C)")
    elif temp < 0:
        raise ValueError(f"{temp} is too cold for plants (min 0°C)")
    return temp


def test_temperature() -> None:
    print("=== Garden Temperature ===")
    print()
    print("Input data is '25'")
    try:
        temp = input_temperature("25")
        print(f"Temperature is now {temp}°C")
    except ValueError as e:
        print(f"Caught input_temperature error: {e}")
    print()
    print("Input data is 'abc'")
    try:
        temp = input_temperature("abc")
        print(f"Temperature is now: {temp}°C")
    except ValueError as e:
        print(f"Caught input_temperature error: {e}")
    print()
    print("Input data is '100'")
    try:
        temp = input_temperature("100")
        print(f"Temperature is now: {temp}°C")
    except ValueError as e:
        print(f"Caught input_temperature: {e}")
    print()
    print("Input data is '-50'")
    try:
        temp = input_temperature("-50")
        print(f"Temperature is now: {temp}°C")
    except ValueError as e:
        print(f"Caught input_temperature: {e}")
    print()
    print("All test completed - program didn't crash!")


if __name__ == "__main__":
    test_temperature()
