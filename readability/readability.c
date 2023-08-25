#include <cs50.h>
#include <math.h>
#include <stdio.h>

int num_letters(string text);
int num_words(string text);
int num_sentences(string text);

int main(void)
{
    // prompt the user for the text
    string text = get_string("Text: ");
    // calculate numbers
    int letters = num_letters(text);
    int words = num_words(text);
    int sentences = num_sentences(text);
    // caculate reading level
    float L = (float) letters / (float) words * 100;
    float S = (float) sentences / (float) words * 100;
    float reading_level = 0.0588 * L - 0.296 * S - 15.8;
    int final = int round(reading_level);
    if (final >= 16)
    {
        printf("Grade 16+");
    }
    else if (final < 1)
    {
        printf("Before grade 1");
    }
    else
    {
        printf("Grade %i\n", (int) round(reading_level));
    }
}
    // count number of letters
int num_letters(string text)
{
    int letter = 0;
    for (int n = 0; text[n] != '\0'; n++)
    {
        if ((text[n] > 64 && text[n] < 91) || (text[n] > 96 && text[n] < 123))
        {
            letter++;
        }
    }
    return letter;
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