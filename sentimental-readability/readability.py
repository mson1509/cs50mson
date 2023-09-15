# TODO
from cs50 import get_int, get_string
def main():
    text = get_string("Text: ")
    letters = num_letters(text)
    words = num_words(text)
    sentences = num_sentences(text)
    level = 0.0588 * letters / words * 100 - 0.296 * sentences / words * 100 - 15.8
    print("Grade: " + level)

def num_letters(text)
    