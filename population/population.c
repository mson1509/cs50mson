#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size

    int x;
    do
    {
        x = get_int("Start size: ");
    }
    while (x < 9);

    // TODO: Prompt for end size

    int y;
    do
    {
        y = get_int("End size: ");
    }
    while (y < x);

    // TODO: Calculate number of years until we reach threshold

    int n;
    for (n = 0; x < y; n++)
    {
        x = x - x/4 +x/3;
    }

    // TODO: Print number of years

    printf ("Years: %i\n", n);

}
