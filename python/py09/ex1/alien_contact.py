from pydantic import Field, ValidationError, BaseModel, model_validator
from enum import Enum
from datetime import datetime


class ContactType(Enum):
    RADIO= "radio"
    VISUAL= "visual"
    PHYSICAL= "physical"
    TELEPATHIC= "telepathic"


class AlienContact(BaseModel):
    contact_id: str = Field(min_length=5, max_length=15)
    timestamp: datetime
    location: str = Field(min_length=3, max_length=300)
    contact_type: ContactType
    signal_strength: float = Field(ge=0.0, le=10.0)
    duration_minutes: int = Field(ge=1, le=1440)
    witness_count: int = Field(ge=1, le=100)
    message_received: str | None = Field(max_length=500, default=None)
    is_verified: bool = False

    @model_validator(mode="after")
    def validate_fields(self):
        if not self.contact_id.startswith("AC"):
            raise ValueError ("The conatct_id should start with 'AC'")
        elif self.contact_type == ContactType.PHYSICAL:
            if self.is_verified is False:
                raise ValueError ("Physical contact must be verified")
        elif self.contact_type == ContactType.TELEPATHIC:
            if self.witness_count < 3:
                raise ValueError ("Telepathic contact requires at " 
                                  "leas 3 witnesses")
        elif self.signal_strength > 7.0:
            if self.message_received is None:
                raise ValueError ("A strong signal(> 7.0) should include " 
                                  "a received messages")
        return self


def main() -> None:
    try:
        contact = AlienContact(
            contact_id = "AC_2024_001",
            timestamp = datetime(2024, 6, 1, 14, 10),
            location = "Area 52, Nevada",
            contact_type = ContactType.TELEPATHIC,
            signal_strength = 8.5,
            duration_minutes = 45,
            witness_count = 5,
            message_received = "Greetings from Zeta Reticult"
        )
    except ValidationError as error:
        print(error.errors()[0]["msg"])
        return

    print("Alien Contact Log Validation")
    print("======================================")
    print("Valid contact report:")
    print(f"ID: {contact.contact_id}")
    print(f"Type: {contact.contact_type}")
    print(f"Location: {contact.location}")
    print(f"Signal: {contact.signal_strength}")
    print(f"Duration: {contact.duration_minutes}")
    print(f"witnesses: {contact.witness_count}")
    print(f"Message: {contact.message_received}")
    print()
    print("======================================")
    print("Expected validation error:")

    try:
        contact = AlienContact(
            contact_id = "AC_2024_001",
            timestamp = datetime(2024, 6, 1, 14, 10),
            location = "Area 52, Nevada",
            contact_type = ContactType.TELEPATHIC,
            signal_strength = 8.5,
            duration_minutes = 45,
            witness_count = 1,
            message_received = "Greetings from Zeta Reticult"
        )
    except ValidationError as error:
        message: str = error.errors()[0]["msg"]
        print(message.removeprefix("Value error, "))
        return


if __name__ == "__main__":
    main()
