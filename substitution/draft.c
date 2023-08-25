#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool only_once_letter(string key);

int main(void)
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
        verify = true;
    }
    else
    {
        verify = false;
    }
    return verify;
}