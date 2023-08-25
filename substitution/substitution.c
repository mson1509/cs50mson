#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool non_alphabetic(string key);
bool only_once_letter(string key);
string convert_lower (string text);
string convert_upper (string text);

int main(int argc, string argv[])
{
    // check whether the key is valid
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
    }
    else if (strlen(argv[2]) != 26)
    {
        printf("Key must contain 26 characters.\n");
    }
    else if (non_alphabetic(argv[2]) == false)
    {
        printf("Key must not contain non-alphabetic characters.\n");
    }
    else if (only_once_letter(argv[2]) == false)
    {
        printf("Key must have each letter exactly once.\n");
    }
    else
    {
        string plain_text = get_string("Plaintext: ");
    }
}
    // convert string to lower
string convert_lower(string text)
{
    bool verify;
    for (int i = 0; text[i] != '\0'; i++)
    {
        tolower(text[i]);
    }
    return text;
}
    // convert string to upper
string convert_upper(string text)
{
    bool verify;
    for (int i = 0; text[i] != '\0'; i++)
    {
        toupper(text[i]);
    }
    return text;
}
    // check the non-alphabetic characters in key
bool non_alphabetic(string key)
{
    bool verify;
    for (int i = 0; key[i] != '\0'; i++)
    {
        if (isupper(key[i]) || islower(key[i]))
        {
            verify = true;
        }
        else
        {
            verify = false;
            break;
        }
    }
    return verify;
}
    // check whether each letter appear only once in key
bool only_once_letter(string key)
{
    string key = convert_lower(key);
    for (char c = 'a'; c <= 'z', c++)
    {

    }
}
    // identify upper characters and convert by key to upper cyphertext
    // identify lower characters and convert by key to lower cyphertext
    // identify non-alphabetic characters and remain same to cyphertext
    // print cyphertext
}