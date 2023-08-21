#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // get the credit card number
    long number;
    number = get_long("Number: ");
    // calculate the checksum
    int x;
    for (int digits = 1; x < 10; digits = digits * 10)
    {
        x = number / digits;
    }
    ///
    long y = number;
    do
    {
        for (int i = 0; i < 2; i ++)
        {
            single_digit = y % 10;
            y = (y - single_digit) / 10;
        }
        int sum = 0;
        if (single_digit < 5)
        {
            sum = sum + single_digit * 2;
        }
        else
        {
            sum = sum + single_digit * 2 - 9;
        }
    ///
    long x = number
    single_digit = x % 10
    x = (x - single_digit) / 10;
    do
    {
        sum = sum + single_digit;
        for (int j = 0; j < 2; j ++)
        {
            single_digit = x % 10;
            x = (x - single_digit) / 10;
        }
        sum = sum + single_digit;
    }
    }
    while (x > 0)
    // determine which type

}