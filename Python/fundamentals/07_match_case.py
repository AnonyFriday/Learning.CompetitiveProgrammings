di: str = input("Enter your direction: ")

# match OR
def direction(direction: tuple[str, str]):
    match direction:
        case ["up", voice] | ["down", voice]:
            print(f"Your voice is: {voice}")
            pass
        case _:
            print("Nothing match here")
            
direction((di, "My voice is heard to the left"))
direction((di, "My voice is heard to the right"))

# if = guard clause
point = tuple(input("Enter x and y: ").split())

match point:
    case (x, y) if (x == y):
        print("diagonal")
    case _:
        print("not diagonal")
        
match point:
    case (x, y) if int(x) > 0 and int(y) > 0:
        print("diagonal positive")
    case _:
        print("not diagonal")
        
match point:
    case (x, y) if int(x) == 0 or int(y) == 0:
        print("diagonal zero")
    case (x, y) if int(x) < 0 and int(y) < 0:
        print("diagonal negative")
    case _:
        print("not diagonal")
    
# using unpacking
commands: list[str] = input("Type your command: ").split(" ")

match commands:
    case [first, *rest] if first == "add":
        for c in commands:
            print(c)
    case [_, second, *rest] if second == "stop":
        print("I love you")
    case _:
        print("Invalid command")

