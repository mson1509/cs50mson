#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // get the credit card number
    long number;
    number = get_long("Number: ");
    // check the credit card's validity
    int x;
    for (int digit = 1; x < 10; digit = digit * 10)
    {
        x = number / digit;
    }
    for ()
    // determine which type

}