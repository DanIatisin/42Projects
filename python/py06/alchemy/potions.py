from .elements import create_air, create_earth
from elements import create_water, create_fire


def healling_potion() -> str:
    return (
        f"Healling potion brewed with '{create_earth()}' " 
        f"and '{create_air()}'")


def strength_potion() -> str:
    return (
    f"Strength potion brewed with '{create_fire()}' "
    f"and '{create_water()}'")