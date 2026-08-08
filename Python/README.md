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

## Phase 2: Advanced CP Topics

## Phase 3: Machine Learning & Data Science Prep

## References

- [Python Execution Model](https://www.geeksforgeeks.org/python/understanding-the-execution-of-python-program/)
