def make_power(expression):
    i = 20
    
    def pow_of(base):
        nonlocal i
        i += 10
        print("i: ", i)
        return pow(base, expression)

    return pow_of

square = make_power(2) 
cube = make_power(3)
print(square(5))
print(cube(5))

