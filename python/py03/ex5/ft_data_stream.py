import random
from typing import Generator


EVENTS: list[str] = ["run", "eat", "sleep", "grab", "move", "climb"]
NAMES: list[str] = ["alice", "bob", "charlie", "dylan"]


def gen_events() -> Generator[tuple[str, str], None, None]:
    while True:
        yield (random.choice(NAMES), random.choice(EVENTS))


def consume_events(events: list[tuple[str, str]]
                   ) -> Generator[tuple[str, str], None, None]:
    while len(events) > 0:
        index = random.randint(0, len(events) - 1)
        yield events.pop(index)


def main() -> None:
    print("=== Game Data Stream Processor ===")
    stream = gen_events()
    for i in range(1000):
        name, action = next(stream)
        print(f"Event {i}: Player {name} did action {action}")
    events = []
    for _ in range(10):
        events.append(next(stream))
    print(f"Built list of 10 events: {events}")
    for event in consume_events(events):
        print(f"Got event from list: {event}")
        print(f"Remains in list: {events}")


if __name__ == "__main__":
    main()
