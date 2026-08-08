# packing tuple into a variable
from typing import Any

data = (10, 20, 30)

# unpack a list or tuple into a variable
x, y, _ = data

print(data)
print(type(data))

print(x, y)

# Extending unpacking
first, *middle, last = [1,2,3,4,5,6]

# Funcition arg packing
def display(*numbers: Any) -> None:
    print(type(numbers))
    for number in numbers:
        print(number)

display(10,20,30, [40, 50])
        
# Dictionary unpacking in function call
def display2(a: Any,b: Any,c: Any) -> None:
    print(a,b,c)    

kwargs = {'a': 10, 'b': 20, 'c': 30}
display2(**kwargs)

# Binary Struct Pack and Unpack
# - packed is the byte object
import struct

packed = struct.pack("i h", 1000, 5); # i is for int and h is for short
print(packed)

val1, val2 = struct.unpack("i h", packed)
print(val1, val2)
