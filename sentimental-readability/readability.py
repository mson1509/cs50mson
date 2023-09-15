# TODO
from cs50 import get_int, get_string
def main():
    text = get_string("Text: ")
    letters = num_letters(text)
    words = num_words(text)
    sentences = num_sentences(text)
    level = 0.0588 * letters / words * 100 - 0.296 * sentences / words * 100 - 15.8
    if level > 16:
        print("Grade: 16+")
    elif level < 1:
        print("Before Grade 1")
    else:
        print ("Grade: " + level)


def num_letters(text)
    letters = 0
    for c in text:
        if c.isalpha():
            letters += 1
    return letters


def num_words(text)
    words = 1
    for c in text:
        if c == " ":
            words += 1
    return words


def num_sentences(text)
    sentences = 0
    for c in text:
        if c == "." or c == "?" or c == "!":
            sentences += 1
    return sentences


