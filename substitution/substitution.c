#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool non_alphabetic(string key);
bool only_once_letter(string key);
string convert_lower (string text);
string convert_upper (string text);
string encrypt (string plaintext);

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
    for (int i = 0; i < strlen(key); i++)
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
    int exclusive_letter_count = 0
    string key = convert_lower(key);
    for (char letter = 'a'; letter <= 'z'; letter++)
    {
        for (i = 0; i < strlen(key); i++)
        {
            if (key[i] == letter)
            {
                exclusive_letter_count++;
                break;
            }
        }
    }
    if (exclusive_letter_count == 26)
    {
        verify = true;
    }
    else
    {
        verify = false;
    }
    return verify;
}

// identify upper characters and convert by key to upper cyphertext
string encrypt (string plaintext)
{
    string plaintext;
    string ciphertext;
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isupper(plaintext[i]))
        {
            ciphertext[i] = plaintext[plaintext[i] - ]
        }
        else if (islower(plaintext[i]))
        {

        }
        else
        {
            cipher[i] = plaintext[i];
        }
    }
}
    // identify lower characters and convert by key to lower cyphertext
    // identify non-alphabetic characters and remain same to cyphertext
    // print cyphertext
}