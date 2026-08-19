from math import pi

# All type of print
def greeting(name: str=''):
    """Output a greeting message"""
    print(f'Hello, {name}')                        # f-string interpolation
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

greeting('John')

def get_pi_number():
    """Return the value of pi"""
    return pi

# Input
name_input = input('Please input your name: ')
greeting(name_input)

print('Pi number value =', get_pi_number())        # string + return value of function
