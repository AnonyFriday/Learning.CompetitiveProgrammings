# creating a tuple
empty_tuple = tuple()
empty_tuple1 = ()
print(empty_tuple)
print(empty_tuple1)
print(type(empty_tuple))
print(type(empty_tuple1))

# length
tpl = ("item1", "item2", "item3")
print(len(tpl))

# positive indexing
tpl = ("item1", "item2", "item3")
first_item = tpl[0]
second_item = tpl[1]

# negative indexing
tpl = ("item1", "item2", "item3", "item4")
first_item = tpl[-4]
second_item = tpl[-3]

# slicing tuples
tpl = ("item1", "item2", "item3", "item4")
all_items = tpl[0:4]  # all items
all_items = tpl[0:]  # all items
middle_two_items = tpl[1:3]  # does not include item at index 3
print(middle_two_items)

# slicing of negative index
tpl = ("item1", "item2", "item3", "item4")
middle_two_items = tpl[-4:-1]
print(middle_two_items)
print(tpl[-3:])
print(tpl[-2:])

# checking item in the tuple
tpl = ("item1", "item2", "item3", "item4")
print("item1" in tpl)

# remove item
# - it's not possible to remove item from the tuple since tuple is immutable
tpl1 = ("item1", "item2", "item3")
del tpl1

# since the tpl1 has been destroyed completly
# print(tpl1)