#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // get the credit card number
    long number;
    number = get_long("Number: ");
    // calculate the checksum
    long x = number;
    int single_digit;
    int sum = 0;
    do
    {
        for (int i = 0; i < 2; i++)
        {
            single_digit = x % 10;
            x = x / 10;
        }
        if (single_digit < 5)
        {
            sum += single_digit * 2;
        }
        else
        {
            sum += single_digit * 2 - 9;
        }
    }
    while (x > 0);

    x = number;
    single_digit = x % 10;
    x = x / 10;
    sum = sum + single_digit;
    do
    {
        for (int i = 0; i < 2; i++)
        {
            single_digit = x % 10;
            x = x / 10;
        }
        sum += single_digit;
    }
    while (x > 0);
    // calculate number of digits
    x = number;
    int digits;
    for (digits = 0; x > 1; digits++)
    {
        x = x / 10;
    }
    // calculate the first two digits
    x = number;
    while (x > 100)
    {
        x = x / 10;
    }
    int first_two = x;
    // check and print results
    if (sum % 10 == 0)
    {
        if (digits == 15 && (first_two == 34 || first_two == 37))
        {
            printf("AMEX\n");
        }
        else if ((digits == 13 || digits == 16) && (first_two / 10) == 4)
        {
            printf("VISA\n");
        }
        else if (digits == 16 && first_two > 50 && first_two < 56)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
        printf("INVALID\n");
}