# TODO
from cs50 import get_string
# take the user input
number = get_string("Number: ")

def every_other_digit(number, from_last_digit):
    digits = []
    current_digit = from_last_digit
    for i in range(len(str(number))):
        if current_digit:
            digit = number % (10 ** (i + 1))
            digits.append(digit)
            current_digit = not current_digit
            i += 1
        else:
            current_digit = not current_digit
            i += 1
    return digits

def sum_of_digits

