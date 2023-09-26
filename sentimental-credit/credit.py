# TODO
from cs50 import get_string
# take the user input
number = get_string("Number: ")

def every_other_digit(number, from_last_digit):
    current_digit = true
    if from_last_digit:
        number %= 10;
