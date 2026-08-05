import copy

# Object Referencing
a = [1,2,3,4]
b = a

print(f"{a} and id of a {id(a)}")
print(f"{b} and id of b {id(b)}")
print()

# Shallow Copy
a2 = [[1,2,3],[3,2,1],[100,100,100], [900,00,992]]
b2 = a2.copy()

print(f"{a2} and id of a2 {id(a2)}")
print(f"{b2} and id of b2 {id(b2)}")

print(f"{a2[0]} and id of a2[0] {id(a2[0])}")
print(f"{b2[0]} and id of b2[0] {id(b2[0])}")
print()

# Deep Copy
a1 = [[1,2,3],[3,2,1],[100,100,100], [900,00,992]]
b1 = copy.deepcopy(a1)

print(f"{a1} and id of a1 {id(a1)}")
print(f"{b1} and id of b1 {id(b1)}")

print(f"{a1[0]} and id of a1[0] {id(a1[0])}")
print(f"{b1[0]} and id of b1[0] {id(b1[0])}")
print()

b1[0] = [4,3,3,2]
print(f"{a1} and id of a1 {id(a1)}")
print(f"{b1} and id of b1 {id(b1)}")

print(f"{a1[0]} and id of a1[0] {id(a1[0])}")
print(f"{b1[0]} and id of b1[0] {id(b1[0])}")
