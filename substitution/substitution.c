#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool non_alphabetic(string key);
int only_once_letter(string key);
string convert_lower (string text);
string convert_upper (string text);
string encrypt (string plaintext, string key);

int main(int argc, string argv[])
{
    // check whether the key is valid
    printf ("%s\n", convert_lower(argv[1]));
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
    }
    else if (non_alphabetic(argv[1]) == false)
    {
        printf("Key must not contain non-alphabetic characters.\n");
    }
    else if (only_once_letter(argv[1]) != 26)
    {
        printf("Key must have each letter exactly once.\n");
    }
    else
    {
       string plain_text = get_string("Plaintext: ");
       string cypher_text = encrypt(plain_text, argv[1]);
       printf("Cyphertext: %s\n", cypher_text);
    }
}

// convert string to lower
string convert_lower(string text)
{
    for (int i = 0; text[i] < strlen(text); i++)
    {
        text[i] = tolower(text[i]);
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
int only_once_letter(string key)
{
    int exclusive_letter_count = 0;
    key = convert_lower(key);
    bool verify;
    for (char letter = 'a'; letter <= 'z'; letter++)
    {
        for (int i = 0; i < strlen(key); i++)
        {
            if (key[i] == letter)
            {
                exclusive_letter_count++;
                break;
            }
        }
    }
    return exclusive_letter_count;
}

// identify upper characters and convert by key to upper cyphertext
string encrypt (string plaintext, string key)
{
    string cyphertext = NULL;
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isupper(plaintext[i]))
        {
            cyphertext[i] = key[plaintext[i] - 65];
            cyphertext[i] = toupper(cyphertext[i]);
        }
        else if (islower(plaintext[i]))
        {
            cyphertext[i] = key[plaintext[i] - 97];
            cyphertext[i] = tolower(cyphertext[i]);
        }
        else
        {
            cyphertext[i] = plaintext[i];
        }
    }
    return cyphertext;
}
