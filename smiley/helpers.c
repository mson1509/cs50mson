#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (image[i][j].rgbtRed == 0x00 && image[i][j].rgbtGreen == 0x00 && image[i][j].rgbtBlue == 0x00)
            {
                continue;
            }
            else if (image[i][j].rgbtRed == 0xff && image[i][j].rgbtGreen == 0xff && image[i][j].rgbtBlue == 0xff)
            {
                image[i][j].rgbtRed = 0x15;
                image[i][j].rgbtGreen = 0x5b;
                image[i][j].rgbtBlue = 0xfb;
            }
        }
    }
}