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

}