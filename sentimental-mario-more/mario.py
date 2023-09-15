# TODO
from cs50 import get_int
height = get_int("Height: ")
while height < 0:
    height = get_int("Height ")
for row in range(height):
    for spaces in range(height - row):
        print(" ")