# Python Competitive Programming & Data Science Roadmap

## Phase 0: Some Coding Conventions

- Identation: 4 spaces per level of indentation
- Commenting: Use triple quotes for multi-line
- Whitespace: Use spaces for indentation, not tab
- Line Length: 80 characters per line
- Naming Conventions: Use snake_case for variable
- Line Breaks: Use line breaks before binary operators

```py
income = (gross_wages
      + deductions
      + taxes
      + other_income
      - ira_deduction
      - student_loan_interest
)
```

- Blank Lines:
  - top-level function and class: 2 blank lines
  - method definition in the class: 1 blank line
- Source File Encoding: UTF-8
- Imports:

```py
# Good
import os
import sys

# Import multiple compoments from a package
from subprocess import Popen, PIPE

# Bad
import sys, os
```

## Phase 1: Python Fundamentals

- ✅: 1. Python env and Execution Model
  - Intepreter Programming Language
  - Compiler: Python Implementation (CPython, PyPy, Jython, IronPython, MicroPython)
  - Interpreter: Python Virtual Machine
  - Virtual Environment: Isolated Environment (venv) for each project

    ```cmd
    # Install virtualenv package
    pip install virtualenv

    # Install specific python runtime
    virtualenv --python=<python310-location> venv/python-310
    virtualenv --python=<python311-location> venv/python-311

    # Activate/decativate specifc environment (Linux)
    source venv/python-311/Scripts/activate
    decativate
    ```

  - Install/ Export Packages

    ```cmd
    # Install a package list
    pip install -r requirements.txt

    # Export package list
    pip freeze > requirements.txt
    ```

- ✅: 2. Import, Input, Output, Comment, Identation, Function, docstring
  - Importing Modules: `import <module_name>`, or 'from math import pi'
  - Identation defines a block of code
  - Comment using #, docstring using """this is a docstring"""
  - Formatting using print, format with {}, f-string
  - Input, Output

    ```py
    # Read from console
    num = input('Please input your name: ')

    # Write to the console
    print(num)
    ```

  - Function

    ```py
    def greet(name):
      print(f'Hello from the other side {name}')
    ```

  - Formatting:

    ```py
    def greeting(name: str=''):
      """Output a greeting message"""
      print(f'Hello, {name}')                         # f-string interpolation
      print('{}, {}{}'.format('Hello', name, '!'))    # str.format() positional
      print('My lucky number is {:04d}'.format(19))   # zero-pad int width 4
      print('My lucky number is {:14d}'.format(19))   # space-pad int width 14
      print('My lucky number is {:14}'.format(19))    # space-pad default width 14
      print('My lucky number is {:014d}'.format(19))  # zero-pad int width 14
      print('My lucky number is {:08.2f}'.format(19)) # zero-pad float width 8, 2 decimals
      print('My lucky number is {:a>10}'.format(19))  # right align, pad 'a'
      print('My lucky number is {:a<10}'.format(19))  # left align, pad 'a'
      print('My lucky number is {:a^10}'.format(19))  # center align, pad 'a'
      print('Have a nice journey with Python.')       # plain text string
      print()                                         # blank line
    ```

- ✅ 3. Primitive & Non-primitive Types

  | Type          | Data Types         | Example                 | Immutability |
  | ------------- | ------------------ | ----------------------- | ------------ |
  | Primitive     |                    |                         | -            |
  |               | int                | x = 1                   | Immutable    |
  |               | float              | x = 2.5                 | Immutable    |
  |               | str                | str = "Python is great" | Immutable    |
  |               | bool               | x = True                | Immutable    |
  |               | complex            | x = 2 + 3j              | Immutable    |
  | Non-primitive |                    |                         | -            |
  |               | list[int]          | x = [1,2,3,4]           | Mutable      |
  |               | dict[int, str]     | {"key1": 1, "key2": 2}  | Mutable      |
  |               | set[int]           | {1,2,3}                 | Mutable      |
  |               | tuple[int,int,int] | x = (1,2,3)             | Immutable    |
  |               | Frozen Set         |                         | Immutable    |
  | None          |                    | x = None                |              |

- ✅ 4. Modify Variables
  - normal
  - global
  - nonlocal

    ```py

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

    ```

- ✅ 5. String Methods
  - Case Conversion
    - `capitalize()`
    - `casefold()`
    - `lower()`
    - `upper()`
    - `swapcase()`
    - `title()`
  - Search & Inspection
    - `count()`
    - `find()`
    - `rfind()`
    - `index()`
    - `rindex()`
    - `startswith()`
    - `endswith()`
  - Splitting & Joining
    - `join()`
    - `partition()`
    - `rpartition()`
    - `split()`
    - `rsplit()`
    - `splitlines()`
  - Alignment & Padding
    - `center()`
    - `ljust()`
    - `rjust()`
    - `zfill()`
    - `expandtabs()`
  - Trimming & Modification
    - `strip()`
    - `lstrip()`
    - `rstrip()`
    - `replace()`
    - `maketrans()`
    - `translate()`
  - String Validation
    - `isalnum()`
    - `isalpha()`
    - `isascii()`
    - `isdecimal()`
    - `isdigit()`
    - `isidentifier()`
    - `islower()`
    - `isnumeric()`
    - `isprintable()`
    - `isspace()`
    - `istitle()`
    - `isupper()`
  - Formatting & Encoding
    - `format()`
    - `format_map()`
    - `encode()`

- ✅ 6. If/else
  - If/else
  - If/elif/else

- ✅ 7. Match/case - Switch/case

  ```py
  def check_status(code: int) -> str:
      match code:
          case 200:
              return "OK"
          case 404:
              return "Not Found"
          case 500:
              return "Server Error"
          case _:
              return "Unknown"
  ```

  - Advanced Sequence & Pattern Matching (`case [...]`)

  ```py
  def process_command(command: list[str]) -> None:
      match command:
          case ["quit"]:
              print("Exiting...")
          case ["go", direction] if direction in ["north", "south", "east", "west"]:
              print(f"Heading {direction}")
          case ["say", *words]:
              print(f"Message: {' '.join(words)}")
          case _:
              print("Unknown command")
  ```

- ✅ 8. Pack and Unpack
  - Pack: group multiple values into single tuple/list
  - Unpack: extract values from tuple/list into multiple variables
  - Dict unpacking (`**`): keys must be strings matching function parameter names

  ```py
  # Tuple / List Packing
  point = 10, 20, 30  # tuple (10, 20, 30)

  # Tuple / List Unpacking
  x, y, z = point  # x=10, y=20, z=30

  # Extended Unpacking with *
  first, *middle, last = [1, 2, 3, 4, 5]  # first=1, middle=[2, 3, 4], last=5

  # Function Arg Packing (*args, **kwargs)
  def add_all(*numbers):
      return sum(numbers)

  # Function Arg Unpacking
  def display(a, b, c):
      print(a, b, c)

  args = [1, 2, 3]
  display(*args)  # 1 2 3

  kwargs = {'a': 10, 'b': 20, 'c': 30}
  display(**kwargs)  # 10 20 30

  # Binary Struct Pack & Unpack (struct module)
  import struct

  packed = struct.pack('i h', 1000, 5)  # bytes
  val1, val2 = struct.unpack('i h', packed)  # 1000, 5
  ```

- ✅ 9. Collection Datatypes & List Operations
  - **4 Main Collection Data Types:**
    - **List `[]`**: Ordered, mutable, allows duplicates.
    - **Tuple `()`**: Ordered, immutable, allows duplicates.
    - **Set `{}`**: Unordered, un-indexed, mutable (can add/remove), NO duplicates.
    - **Dictionary `{k: v}`**: Ordered (Py 3.7+), mutable, keyed, NO duplicate keys.

  - **List Operations & Methods Summary:**
    - **Create**: `lst = []` or `lst = list()`
    - **Access**: Positive indexing `lst[0]`, Negative indexing `lst[-1]`
    - **Slicing**: `lst[start:end:step]` (e.g. `lst[::-1]` reverses list)
    - **Unpack**: `a, b, *rest = lst`
    - **Modify / Add**: `lst[0] = val`, `lst.append(item)`, `lst.insert(index, item)`, `lst.extend(other_lst)`
    - **Remove**: `lst.remove(item)` (by value), `lst.pop(index)` (by index, default last), `del lst[index]`, `lst.clear()`
    - **Utility**: `len(lst)`, `lst.copy()`, `lst.count(item)`, `lst.index(item)`
    - **Sort & Reverse**: `lst.reverse()`, `lst.sort(reverse=True)` (in-place), `sorted(lst)` (returns new list)

  - **Tuple Operations & Characteristics Summary:**
    - **Characteristics**: Immutable (unchangeable), ordered, allows duplicate elements.
    - **Creation**: `tpl = ()`, `tpl = tuple()`, single item needs comma: `tpl = (1,)` or `1,`
    - **Access & Slicing**: Indexing `tpl[0]`, `tpl[-1]`, Slicing `tpl[1:3]` (returns new tuple)
    - **Built-in Methods**: Only two: `tpl.count(item)` and `tpl.index(item)`
    - **Join & Search**: Concatenate `tpl1 + tpl2`, Check existence `'item' in tpl`
    - **Delete**: `del tpl` (deletes entire tuple variable; individual item deletion forbidden)
    - **Mutation Workaround**: Convert to list `lst = list(tpl)`, modify, convert back `tpl = tuple(lst)`

- ✅ 10. Lambda (Anonymous Functions)
  - **Syntax**: `lambda arguments: expression`
  - **Usage with `map()` / `filter()` / `sorted()`**:

  ```py
  # Map with lambda
  nums = (1, 2, 3, 4)
  squares = list(map(lambda x: x * x, nums))

  # Filter with lambda
  words = ("apple", "banana", "cherry", "fig")
  longest = list(filter(lambda w: len(w) == 6, words))
  ```

- ✅ 11. OOP (Object-Oriented Programming)
  - **Core Concepts:**
    - `__init__(self, ...)`: Constructor method, runs automatically on object creation.
    - `self`: Reference to current instance (equivalent to C# `this`). Must be explicitly defined as 1st parameter.
  - **4 Pillars of OOP:**
    - **Encapsulation**: Hide data using access conventions (`_protected` single underscore, `__private` double underscore name mangling).
    - **Inheritance**: Derived classes inherit from base classes via `class Child(Parent):` and call `super().__init__()`.
    - **Polymorphism**: Override base class methods in child classes.
    - **Abstraction**: Use `abc.ABC` and `@abstractmethod` decorator to enforce interface contracts.

  ```py
  from abc import ABC, abstractmethod

  # Abstraction: Abstract Base Class
  class AbstractAnimal(ABC):
      @abstractmethod
      def make_sound(self):
          pass

  # Base Class (Encapsulation + Abstract Implementation)
  class Bird(AbstractAnimal):
      def __init__(self, name: str):
          self.__name = name  # Private attribute (Encapsulation)

      def get_name(self) -> str:
          return self.__name

      def make_sound(self):
          print(f"{self.__name} chirps.")

      def fly(self):
          print(f"{self.__name} can fly.")

  # Inheritance & Polymorphism
  class Penguin(Bird):
      def __init__(self, name: str):
          super().__init__(name)  # Call parent constructor

      # Polymorphism: Method Overriding
      def fly(self):
          print(f"{self.get_name()} cannot fly.")

      def swim(self):
          print(f"{self.get_name()} can swim.")
  ```

- ✅ 12. Closure
  - Pros:
    - contains nested function
    - references a value in main scope
    - main function returns nested one
  - Cons:
    - avoid use of global values
    - provide a form of data hiding
    - Good to use when there few methods/attributes to define a class

  ```py
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
  ```

- ✅ 13. Decorator
  - Can be used for validating input data
  - Filtering, mapping output data
  - Middleware / interceptor / logging
  - Function wraps another function, adds behavior without changing original code

  ```py
  # Manual decoration
  def make_pretty(input_func):
      def decorate():
          print("I got additional decoration.")
          input_func()
      return decorate

  def ordinary():
      print("I am ordinary.")

  pretty = make_pretty(ordinary)
  pretty()

  # Decorator syntax (@) with *args and **kwargs
  def make_pretty_2(input_func):
      def decorate(*args, **kwargs):
          print("I got additional decoration.")
          return input_func(*args, **kwargs)
      return decorate

  @make_pretty_2
  def say_hello(name):
      print(f"Hello: {name}")

  say_hello("MONEY")
  ```

- ✅ 14. Generators & Iterators & Yields
  - **Iterable**: Object with `__iter__()` returning iterator (list, tuple, string)
  - **Iterator**: Object with `__next__()` producing items one by one on demand (`StopIteration` on empty)
  - **Generator (`yield`)**: Function that pauses execution, saves state, yields value lazily (O(1) memory)
  - **`yield from`**: Delegates directly to sub-iterable / sub-generator
  - **Pros**:
    - O(1) memory footprint (handles infinite streams / gigabyte files)
    - Instant time-to-first-item (no waiting for full list build)
    - Pipeline composability without intermediate memory buffers
  - **Drawbacks**:
    - **One-time use only**: exhausted after single pass, cannot iterate twice
    - **No random access**: cannot index `gen[i]` or slice `gen[start:end]`
    - **No `len()`**: size unknown beforehand without consuming entire stream
    - **Serialization**: cannot directly serialize to JSON without converting to list
    - **Debugging complexity**: exceptions trigger lazily during consumption

  ```py
  # 1. Generator function (lazy evaluation)
  def count_up_to(limit):
      count = 1
      while count <= limit:
          yield count  # Pause and return value
          count += 1

  # 2. Consume items on demand
  counter = count_up_to(3)
  print(next(counter))  # 1
  print(next(counter))  # 2
  print(next(counter))  # 3

  # 3. Generator expression (low memory) vs List
  gen_exp = (x * x for x in range(1000000))  # Minimal RAM

  # 4. yield from delegation
  def chain_items():
      yield from [1, 2]
      yield from ["a", "b"]

  print(list(chain_items()))  # [1, 2, 'a', 'b']
  ```

- ✅ 15. Modules

## Phase 3: Machine Learning & Data Science Prep

## References

- [Python Execution Model](https://www.geeksforgeeks.org/python/understanding-the-execution-of-python-program/)

```

```
