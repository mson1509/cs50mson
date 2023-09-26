# TODO
from cs50 import get_string
# take the user input
number = get_string("Number: ")

def every_other_digit(number, from_last_digit):
    current_digit = True
    if from_last_digit:
        for i in range(1, len(str(number)) + 1)
            if current_digit:
                digit = number % (10 ** i)
                current_digit = not current_digit
                i += 1
            else:

    else:
        current_digit = not current_digit
