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
    int y = number;
    do
    {
        for (int i = 0; i < 2; i ++)
        {
            single_digit = y % 10;
            y = (y - single_digit) / 10;
        }
        int sum = 0;
        sum = sum + single_digit * 2;

    }
    while (y > 0)
    // determine which type

}