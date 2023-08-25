#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // check whether the key is right
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
    }
    else if (strlen(argv[2]) != 26)
    {
        printf("Key must contain 26 characters.\n");
    }
    else if (isupper(argv[2]) == false || islower(argv[2]) == false)
    {
        printf("Key must not contain non-alphabetic characters.\n");
    }
    else if ()
    else
    {
        string plain_text = get_string("Plaintext: ");
    }
    // identify upper characters and convert by key to upper cyphertext

    // identify lower characters and convert by key to lower cyphertext

    // identify non-alphabetic characters and remain same to cyphertext

    // print cyphertext
}