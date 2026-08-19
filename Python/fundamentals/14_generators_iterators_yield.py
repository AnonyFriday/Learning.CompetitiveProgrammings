import sys

# ==========================================
# 1. ITERABLE VS ITERATOR
# ==========================================
numbers = [10, 20, 30]  # Iterable
num_iter = iter(numbers)  # Iterator

print("--- 1. Manual Iteration ---")
print(next(num_iter))  # 10
print(next(num_iter))  # 20
print(next(num_iter))  # 30
# print(next(num_iter)) # Raises StopIteration

# How for-loop works under hood:
str_iter = iter("HI")
while True:
    try:
        char = next(str_iter)
        print(f"Char: {char}")
    except StopIteration:
        break
    
# ==========================================
# 2. CUSTOM ITERATOR CLASS
# ==========================================

class Countdown:
    """Custom Iterator: Counts down from start to 1"""

    def __init__(self, start: int):
        self.current = start

    def __iter__(self):
        return self

    def __next__(self):
        if self.current <= 0:
            raise StopIteration
        val = self.current
        self.current -= 1
        return val


print("\n--- 2. Custom Iterator Class ---")
for num in Countdown(3):
    print(f"Countdown: {num}")

# ==========================================
# 3. GENERATOR FUNCTION (yield)
# ==========================================

def countdown_gen(start: int):
    """Generator: Same as Countdown class, but concise"""
    current = start
    while current > 0:
        yield current
        current -= 1

print("\n--- 3. Generator Function ---")
gen = countdown_gen(3)
print(next(gen))  # 3
print(next(gen))  # 2
print(next(gen))  # 1

# =============================================
# 4. GENERATOR EXPRESSION & MEMORY EFFICIENCY
# =============================================

# List Comprehension: creates full list in memory immediately
list_comp = [x * x for x in range(1000000)]

# Generator Expression: yields on demand, minimal memory
gen_exp = (x * x for x in range(1000000))

print("\n--- 4. Memory Comparison ---")
print(f"List size in RAM:      {sys.getsizeof(list_comp)} bytes")
print(f"Generator size in RAM: {sys.getsizeof(gen_exp)} bytes")

# ==========================================
# 5. GENERATOR PIPELINE & yield from
# ==========================================

def read_numbers(limit: int):
    for i in range(1, limit + 1):
        yield i

def filter_evens(nums):
    for n in nums:
        if n % 2 == 0:
            yield n

def square_all(nums):
    for n in nums:
        yield n * n

# Subgenerator delegation with `yield from`
def chained_gen():
    yield from range(1, 4)
    yield from ["a", "b", "c"]

print("\n--- 5. Generator Pipeline & yield from ---")
pipeline = square_all(filter_evens(read_numbers(10)))
print(f"Pipeline result: {list(pipeline)}")         # [4, 16, 36, 64, 100]
print(f"Chained items:   {list(chained_gen())}")