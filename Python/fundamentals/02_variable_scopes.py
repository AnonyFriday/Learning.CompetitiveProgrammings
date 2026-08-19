a = "global"

def func_1():
    """Sample function 1"""
    a = 10
    print("func_1 - value of a:", a)

func_1()
print("Global - value of a: ", a)
print()

# Using global variable
b = "global-"

def func_2():
    """Sample function 2, using the global variable"""
    global b # referencing the global variable
    b *= 2
    print("func_2 0 Value of b: ", b)

func_2()
print("Global - value of b: ", b)
print()

# Using local
c = "global"

def outer() -> None:
    c = "local"
    def inner() -> None:
        nonlocal c # referening the outer scope, instead create a new copy of c in this inner functiom
        c = "non-local" 
        print("Inner - value of c", c)
    inner()
    print("Outer - value of c: ", c)

outer()
print("global: ", c)
print()

# Combining both nonlocal and global
x = "global_var"

def outer1() -> str:
    x = "enclosing_var"

    def use_global() -> None:
        global x
        x = "changed_global"

    def use_nonlocal() -> None:
        nonlocal x
        x = "changed_nonlocal"
    use_global()
    use_nonlocal()
    return x

print(x) # global_var
print(outer1()) # changed_nonlocal
print(x) # changed_global
