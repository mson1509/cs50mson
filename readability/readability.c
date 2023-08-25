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
    int reading_level = 0.0588 * (letters / word) * 100 - 0.296 * (sentences / word) * 100 - 15.8;
    printf(" Grade %i\n", reading_level);
}
    // count number of letters
int num_letters(string text)
{
    int length;
    for (int n = 0; text[n] != 0; n++)
        length = n;
    

}
    // count number of words
int num_words(string text)
{

}
    // count number of sentences
int num_sentences(string text)
{

}