#include <cs50.h>
#include <stdio.h>

int main(void)
{
 // Ask for the pyramids' height
int height;
do
{
    height = get_int("Height of the pyramids is: ");
}
while (height < 1 || height > 8);

 // Print the pyramids
int row;
for (row = 1; row <= height; row++)
{
    for (int i = 0; i < height - row; i++)
    {
        printf(" ");
    }
    for (int j = 0; j < row; j++)
    {
        printf("#");
    }
    printf("  ");
    for (int h = 0; h < row; h++)
    {
        printf("#");
    }
    printf("\n");
}
}