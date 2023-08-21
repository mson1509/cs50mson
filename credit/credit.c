#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // get the credit card number
    long number;
    number = get_long("Number: ");
    // calculate the checksum
    long x = number;
    do
    {
        for (int i = 0; i < 2; i ++)
        {
            single_digit = x % 10;
            x = (x - single_digit) / 10;
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
    while (x > 0);
    }
    ///
    x = number;
    single_digit = x % 10;
    x = (x - single_digit) / 10;
    sum = sum + single_digit;
    do
    {
        for (int i = 0; j=i < 2; i ++)
        {
            single_digit = x % 10;
            x = (x - single_digit) / 10;
        }
        sum = sum + single_digit;
    }
    while (x > 0)
    // determine which type
    long ;
    for (digits = 1; z > 1; digits ++)
    {
        z = number / 10;
    }


    //

}