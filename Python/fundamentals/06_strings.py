# String Escape
print("I hope everyone is enjoying the Python Challenge.\nAre you ?")  # line break
print("Days\tTopics\tExercises")  # adding tab space or 4 spaces
print("Day 1\t5\t5")
print("Day 2\t6\t20")
print("Day 3\t5\t23")
print("Day 4\t1\t35")
print("This is a backslash  symbol (\\)")
print('In every programming language it starts with "Hello, World!"')

# String Formatting (old)
first_name = "Asabeneh"
last_name = "Yetayeh"
language = "Python"
formatted_string = "I am %s %s. I teach %s" % (first_name, last_name, language)
print(formatted_string)

radius = 10
pi = 3.14
area = pi * radius**2
formatted_string = "The area of circle with a radius %d is %.2f." % (radius, area)

python_libraries = ["Django", "Flask", "NumPy", "Matplotlib", "Pandas"]
formated_string = "The following are python libraries:%s" % (python_libraries)
print(
    formated_string
)  # "The following are python libraries:['Django', 'Flask', 'NumPy', 'Matplotlib','Pandas']"


# String Formatting (new)
a = 4
b = 3

print("{} + {} = {}".format(a, b, a + b))
print("{} - {} = {}".format(a, b, a - b))
print("{} * {} = {}".format(a, b, a * b))
print("{} / {} = {:.2f}".format(a, b, a / b))  # limits it to two digits after decimal
print("{} % {} = {}".format(a, b, a % b))
print("{} // {} = {}".format(a, b, a // b))
print("{} ** {} = {}".format(a, b, a**b))

# String Interpolation
a = 4
b = 3
print(f"{a} + {b} = {a +b}")
print(f"{a} - {b} = {a - b}")
print(f"{a} * {b} = {a * b}")
print(f"{a} / {b} = {a / b:.2f}")
print(f"{a} % {b} = {a % b}")
print(f"{a} // {b} = {a // b}")
print(f"{a} ** {b} = {a ** b}")

# Slicing a string
language = "python"
print(language[:3])  # 'pyt'
print(language[0:2])  # 'py'
print(language[1])  # 'y'

# Reversing a String
print(language[::-1])

# Skipping characters in a string
print(language[::2])  # 'pto'

# String Methods
challenge = "thirty days of python"
print(challenge.capitalize())  # 'Thirty days of python'
print(challenge.count("y"))  # 3
print(challenge.count("y", 7, 14))  # 1,
print(challenge.count("th"))  # 2`
print(challenge.endswith("on"))  # True
print(challenge.endswith("tion"))  # False
print(challenge.expandtabs(6))
print(repr(challenge.expandtabs((6)).find("d")))
print(challenge.rfind("y"))
print(challenge.index("d", 3, 10))
print("123123czxc".isalnum())
print(challenge.isalpha())
print(challenge.isdigit())
print(challenge.isdecimal())
print("123_name".isidentifier())  # false because it start with numeric
print("22222".islower())
print("PYTHON".isupper())

web_tech = ["HTML", "CSS", "Javascript", "React"]
print("aaaa".join((web_tech)))  # HTML CSS Javascript React

challenge = "thirty days of pythoonnn"
print(challenge.strip("noth"))  # 'irty days of py'

challenge = "money"
print(challenge.replace("mo", "22"))

challenge = "monkey in town"
print(challenge.title())  # Money In Town

print(challenge.swapcase())

print(challenge.startswith("monkey"))
