#include <cs50.h>
#include <stdio.h>

int num_letters(string text);
int num_words(string text);
int num_sentences(string text);

int main(void)
{
    // prompt the user for the text
    string text = get_string("Text: ");
    // calculate reading level
    int letters = num_letters(text);
    int words = num_words(text);
    int sentences = num_sentences(text);
    int reading_level = 0.0588 * (letters / words) * 100 - 0.296 * (sentences / words) * 100 - 15.8;
    printf(" Grade %i\n", reading_level);
}
    // count number of letters
int num_letters(string text)
{
    int length = 0;
    for (int n = 0; text[n] != '\0'; n++)
    {
        if (text[n] > 64 && text[n] < 91) || (text[n] > 96 && text[n] < 123)
        {
            length++;
        }
    }
    return length;
}
    // count number of words
int num_words(string text)
{
    int spaces = 1;
    for (int n = 0; text[n] != '\0'; n++)
    {
        if (text [n] == ' ')
        {
            spaces++;
        }
    }
    return spaces;
}
    // count number of sentences
int num_sentences(string text)
{
    int marks = 0;
    for (int n = 0; text[n] != '\0'; n++)
    {
        if (text[n] == '.' || text[n] == '!' || text[n] == '?')
        {
            marks++;
        }
    }
    return marks;

}