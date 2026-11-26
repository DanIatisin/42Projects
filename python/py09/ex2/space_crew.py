from enum import Enum
from pydantic import BaseModel, ValidationError, model_validator, Field
from datetime import datetime

class Rank(Enum):
    CADET= "cadet"
    OFFICER= "officer"
    LIEUTENANT = "lieutenant"
    CAPTAIN = "captain"
    COMMANDER = "commander"


class CrewMember(BaseModel):
    member_id: str = Field(min_length=3, max_length=10)
    name: str = Field(min_length=2, max_length=50)
    rank: Rank
    age: int = Field(ge=18, le=80)
    specialization: str = Field(min_length=3, max_length=30)
    years_experience: int = Field(ge=0, le=50)
    is_active: bool = True


class SpaceMission(BaseModel):
    mission_id: str = Field(min_length=5, max_length=15)
    mission_name: str = Field(min_length=3, max_length=100)
    destination: str = Field(min_length=3, max_length=50)
    launch_date: datetime
    duration_days: int = Field(ge=1, le=3650)
    crew: list[CrewMember] = Field(min_length=1, max_length=12)
    mission_status: str = "Planned"
    budget_millions: float = Field(ge=1.0, le=10000.0)

    @model_validator(mode="after")
    def validate_mission(self) -> SpaceMission:
        if not self.mission_id.startswith("M"):
            raise ValueError("The mission id should start with M")
        elif not any(
            member.rank in (Rank.COMMANDER, Rank.CAPTAIN)
            for member in self.crew
        ):
            raise ValueError("Mission requires at least one Commander or Captain")
        elif self.duration_days > 365:
            if (sum(member.years_experience >= 5 
            for member in self.crew) < len(self.crew) / 2
            ):
                raise ValueError("Mission longer than 365 days requires at least "
                             "50% crew with 5+ years experience")
        elif any(member.is_active is False for member in self.crew):
            raise ValueError("All crew members must be valid")
        return self


valid_crew_data = [
    {"member_id": "C001", "name": "Sarah Connor", "rank": Rank.COMMANDER,
     "age": 35, "specialization": "Mission Command", "years_experience": 10},
    {"member_id": "N005", "name": "John Smith", "rank": Rank.LIEUTENANT,
     "age": 40, "specialization": "Navigation", "years_experience": 15},
    {"member_id": "E010", "name": "Alice Johnson", "rank": Rank.OFFICER,
     "age": 38, "specialization": "Engineering", "years_experience": 10}
]


invalid_crew_data = [
    {"member_id": "C001", "name": "Sarah Connor", "rank": Rank.OFFICER,
     "age": 35, "specialization": "Mission Command", "years_experience": 10},
    {"member_id": "N005", "name": "John Smith", "rank": Rank.LIEUTENANT,
     "age": 40, "specialization": "Navigation", "years_experience": 15},
    {"member_id": "E010", "name": "Alice Johnson", "rank": Rank.OFFICER,
     "age": 38, "specialization": "Engineering", "years_experience": 10}
]


def main() -> None:
    try:
        mission = SpaceMission(
            mission_id="M2024_MARS",
            mission_name="Mars Colony Establishment",
            destination="Mars",
            launch_date=datetime(2024,6,9,8,35),
            duration_days=900,
            crew=[CrewMember(**member) for member in valid_crew_data],
            mission_status="In progress",
            budget_millions=2500.0
        )
    except ValidationError as error:
        message: str = error.errors()[0]["msg"]
        print(message.removeprefix("Value error, "))

    print("Space Mission Crew Validation")
    print("=====================================")
    print("Valid mission created:")
    print(f"Mission: {mission.mission_name}")
    print(f"ID: {mission.mission_id}")
    print(f"Destination: {mission.destination}")
    print(f"Duration: {mission.duration_days} days")
    print(f"Budget: ${mission.budget_millions}M")
    print(f"Crew size: {len(mission.crew)}")

    for member in mission.crew:
        print(f"- {member.name} ({member.rank.value}) - {member.specialization}")

    print()
    print("=====================================")
    print("Expected validation error:")

    try:
        mission = SpaceMission(
            mission_id="M2024_MARS",
            mission_name="Mars Colony Establishment",
            destination="Mars",
            launch_date=datetime(2024,6,9,8,35),
            duration_days=900,
            crew=[CrewMember(**member) for member in invalid_crew_data],
            mission_status="In progress",
            budget_millions=100.5
        )
    except ValidationError as error:
        message = error.errors()[0]["msg"]
        print(message.removeprefix("Value error, "))


if __name__ == "__main__":
    main()