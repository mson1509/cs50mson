#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // get the credit card number
    long number;
    number = get_long("Number: ");
    // check the credit card's validity
    int x;
    for (int digits = 1; x < 10; digits = digits * 10)
    {
        x = number / digits;
    }
    int single_digit;
    for (y = number; y > 0; y = (y - single_digit)/10 )
    {
        single_digit = y % 10
    }
    // determine which type

}