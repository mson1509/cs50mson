#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool only_once_letter(string key);

int main(void)
{
    string text = "YTNSHKVEFXRBAUQZCLWDMIPGJO";
    for (int i = 0; i] < strlen(text); i++)
    {
        text[i] = tolower(text[i]);
    }
    printf("%s\n", text);
}