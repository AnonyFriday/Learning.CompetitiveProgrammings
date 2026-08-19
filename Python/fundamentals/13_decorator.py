# Takes in a function, adds some functionality and returns it 
# Function wrap another function, add behavior without change original code.

def make_pretty(input_func):
    def decorate():
        print("I got additional decoration.")
        input_func()
    return decorate

def ordinary():
    print("I am ordinary.")

ordinary()
pretty = make_pretty(ordinary)
pretty()

# Use it as the decorattor (in C#, it's Attribute)
# syntatic sugar for say_hello = make_pretty(say_hello)
# *args: unpacking the list or tuple
# **kwargs: unpacking the dictionary
def make_pretty_2(input_func):
    def decorate(*args, **kwargs):
        print(args)
        print(kwargs)
        print("I got additional decoration.")
        input_func(*args, **kwargs)
    return decorate

@make_pretty_2
def say_hello(name, age):
    print(f"Hello: {name} - {age}")

say_hello("MONEY", 20)
say_hello(**{"name": "love you", "age": 19999})