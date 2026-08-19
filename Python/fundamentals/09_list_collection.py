# Create a List
from typing import Any

lst: list[Any] = list()
lst2: list[Any] = []
print(lst)
print(lst2)

print(len(lst))
print(len(lst2))

# List contains difference datatype
lst = ['baba', ['ill', 'dawn', 'son'], 1]

# Accesing using possive index
print(lst[2])

# Accesing using negative index
print(lst[-2])

# Slicing from a list
# - third argument a step

print(lst[0:])
print(lst[:2])
print(lst[::2])

# Use append
lst.append('lime')
print(lst)

# Use insert for adding element at the specific index
lst.insert(5, "cheese")
print(lst)

# Use remove to delete an item from list
lst.remove("lime")
print(lst)

# Use pop
lst.pop()
lst.pop(0)
print(lst)

# use del
lst = ['item1', 'item2', 'item3']
del lst[1:3]
print(lst)

# clear
fruits = ['banana', 'orange', 'mango', 'lemon', 'kiwi', 'lime']
fruits.clear()

print(fruits)

# joining a list
list1 = [1,2,3]
list2 = [4,4,4]
list3 = list1 + list2
print(list3)

# extend
list1 = ['item1', 'item2']
list2 = ['item3', 'item4', 'item5']
list1.extend(list2)
print(list1)

# reverse
lst = ['item1', 'item2', 'item3']
lst.reverse()
print(lst)

# sort
lst = ['item1', 'item2', 'item3', '4 items']
lst.sort()
print(lst)

lst.sort(reverse=True)
print(lst)

# sorted
# - return the ordered list without modifying the original list
lst = ['item1', 'item2', 'item3', '4 items']
print(sorted(lst))
print(lst)
