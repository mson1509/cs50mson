# TODO
from cs50 import get_int
# take the user input
def main():
    number = get_int("Number: ")
    digits = every_other_digit(number, False)
    print(digits)
    print(every_other_digit(number, True))
    total = add_products_digits (digits)
    print(total)
    total += sum(every_other_digit(number, True))
    print(total)
    if (total % 10) != 0:
        print("INVALID")
    elif len(str(number)) == 15 and str(number)[0] == 3 and (str(number)[1] == 4 or str(number)[1] == 7):
        print("AMEX")
    elif len(str(number)) == 16 and str(number)[0] == 5 and str(number)[1] < 6 and str(number)[1] > 0:
        print("MASTERCARD")
    elif (len(str(number)) == 13 or len(str(number)) == 16) and str(number)[0] == 4:
        print("VISA")
    return

def every_other_digit(number, from_last_digit):
    digits = []
    current_digit = from_last_digit
    for i in range(len(str(number))):
        if current_digit:
            digit = round(number % 10)
            digits.append(digit)
            number = round(number / 10)
            current_digit = not current_digit
            i += 1
        else:
            number = round(number / 10)
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

