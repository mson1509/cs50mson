# TODO
from cs50 import get_int

height = get_int("Height: ")
while height < 0 or height > 8:
    height = get_int("Height ")
for row in range(1, height + 1, 1):
    for spaces in range(height - row):
        print(" ", end="")
    for first in range(row):
        print("#", end="")
    print("  ", end="")
    for second in range(row):
        print("#", end="")
    print()
