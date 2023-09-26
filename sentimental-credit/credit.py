# TODO
from cs50 import get_int
import math
# take the user input
def main():
    number = get_int("Number: ")
    digits = every_other_digit(number, False)
    print(every_other_digit(number, True))
    total = add_products_digits (digits)
    total += sum(every_other_digit(number, True))
    num_digits = len(str(number))
    first_digit = int(str(number)[0])
    second_digit = int(str(number)[1])
    if (total % 10) != 0:
        print("INVALID")
    elif num_digits == 15 and first_digit == 3 and (second_digit == 4 or second_digit == 7):
        print("AMEX")
    elif num_digits == 16 and first_digit == 5 and second_digit < 6 and second_digit > 0:
        print("MASTERCARD")
    elif (num_digits == 13 or num_digits == 16) and first_digit == 4:
        print("VISA")
    return

def every_other_digit(number, from_last_digit):
    digits = []
    current_digit = from_last_digit
    for i in range(len(str(number))):
        if current_digit:
            digit = math.floor(number % 10)
            digits.append(digit)
            number = math.floor(number / 10)
            current_digit = not current_digit
            i += 1
        else:
            number = math.floor(number / 10)
            current_digit = not current_digit
            i += 1
    return digits

def add_products_digits (digits):
    sum = 0
    for digit in digits:
        digit *= 2
        if len(str(digit)) == 2:
            sum += int(str(digit)[0])
            sum += int(str(digit)[1])
        else:
            sum += digit
    return sum

main()

