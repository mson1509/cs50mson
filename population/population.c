#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size

    int n;
    do
    {
        n = get_int("Start size: ");
    }
    while (n < 9);
    return n;

    // TODO: Prompt for end size

    int m;
    do
    {
        m = get_int("End size: ");
    }
    while (m < n);
    return m;

    // TODO: Calculate number of years until we reach threshold
    int x;
    
    // TODO: Print number of years
}
