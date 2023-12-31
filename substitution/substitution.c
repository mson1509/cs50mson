#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool non_alphabetic(string key);
bool only_once_letter(string key);
string convert_lower (string text);
string encrypt (string plaintext, string key);

int main(int argc, string argv[])
{
    // check whether the key is valid
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else if (non_alphabetic(argv[1]) == false)
    {
        printf("Key must not contain non-alphabetic characters.\n");
        return 1;
    }
    else if (only_once_letter(argv[1]) == false)
    {
        printf("Key must have each letter exactly once.\n");
        return 1;
    }
    else
    {
       string plain_text = get_string("plaintext: ");
       string cypher_text = encrypt(plain_text, argv[1]);
       printf("ciphertext: %s\n", cypher_text);
       return 0;
    }
}

// convert string to lower
string convert_lower(string text)
{
    for (int i = 0; i < strlen(text); i++)
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
bool only_once_letter(string key)
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
    if (exclusive_letter_count == 26)
    {
        return true;
    }
    else
    {
        return false;
    }
    return verify;
}

// identify upper characters and convert by key to upper cyphertext
string encrypt (string plaintext, string key)
{
    string cyphertext = plaintext;
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
