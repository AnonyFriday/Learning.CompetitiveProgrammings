print("Hello World")

# Operator

print(2 + 3)   # addition(+)
print(3 - 1)   # subtraction(-)
print(2 * 3)   # multiplication(*)
print(3 + 2)   # addition(+)
print(3 - 2)   # subtraction(-)
print(3 * 2)   # multiplication(*)
print(3 / 2)   # division(/)
print(3 ** 2)  # exponential(**)
print(3 % 2)   # modulus(%)
print(30 // 7)  # Floor division operator(//)

# Data Types
print(type(10))                     # Int
print(type(3.14))                   # Float
print(type(1 + 3j))                 # Complex
print(type('Asabeneh'))             # String
print(type([1, 2, 3]))              # List
print(type({'name': 'Asabeneh'}))   # Dictionary
print(type({9.8, 3.14, 2.7}))       # Set
print(type(None))                   # NoneType
print(type((4,5,6,6)))              # Tuple

# Proving Immmutability
# - difference address when adding a value to an integer variable

a: int = 10
print(id(a))
a += 20
print(id(a))

# - same address when adding a value to a list
b: dict[int, str] = {}
print(id(b))
b.update({1:'Asabeneh'})
print(id(b))

c: set[int] = {1}
print(id(c))
c.add(10)
print(id(c))

d: tuple[int, int] = (1,1)
print(id(d))
d = (3,4)
print(id(d))