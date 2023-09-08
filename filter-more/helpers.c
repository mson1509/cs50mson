#include "helpers.h"
#include <math.h>

void swap(RGBTRIPLE *a, RGBTRIPLE *b);
int avg1(int i, int j, int height, int width, char color, RGBTRIPLE image[height][width]);
int avg2(int i, int j, int height, int width, char color, RGBTRIPLE image[height][width]);

int const num_color_channels = 3;

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float gray_pixel = (float) (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / (float) num_color_channels;
            image[i][j].rgbtBlue = round(gray_pixel);
            image[i][j].rgbtGreen = round(gray_pixel);
            image[i][j].rgbtRed = round(gray_pixel);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        if (width % 2 == 0)
        {
            for (int j = 0; j < (width / 2); j++)
            {
                swap(&image[i][j], &image[i][width - 1 - j]);
            }
        }
        else
        {
            for (int j = 0; j < ((width - 1) / 2); j++)
            {
                swap(&image[i][j], &image[i][width - 1 - j]);
            }
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = avg1(i, j, height, width, 'b', copy);
            image[i][j].rgbtGreen = avg1(i, j, height, width, 'g', copy);
            image[i][j].rgbtRed = avg1(i, j, height, width, 'r', copy);
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = avg2(i, j, height, width, 'b', copy);
            image[i][j].rgbtGreen = avg2(i, j, height, width, 'g', copy);
            image[i][j].rgbtRed = avg2(i, j, height, width, 'r', copy);
        }
    }
    return;
}

void swap(RGBTRIPLE *a, RGBTRIPLE *b)
{
    RGBTRIPLE temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int avg1(int i, int j, int height, int width, char color, RGBTRIPLE image[height][width])
{
    int sum = 0;
    int count = 0;
    for (int column = (i - 1); column <= (i + 1); column++)
    {
        for (int row = (j - 1); row <= (j + 1); row++)
        {
            if ((column < 0) || (row < 0) || (column >= height) || (row >= width))
            {
                continue;
            }
            else
            {
                switch (color)
                {
                    case 'b':
                        sum += image[column][row].rgbtBlue;
                        count++;
                        break;
                    case 'g':
                        sum += image[column][row].rgbtGreen;
                        count++;
                        break;
                    case 'r':
                        sum += image[column][row].rgbtRed;
                        count++;
                        break;
                }
            }
        }
    }
    int avg = round((float) sum / count);
    return avg;
}

int avg2(int i, int j, int height, int width, char color, RGBTRIPLE image[height][width])
{
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    int x = 0;
    int y = 0;
    for (int column = (i - 1); column <= (i + 1); column++)
    {
        for (int row = (j - 1); row <= (j + 1); row++)
        {
            if ((column < 0) || (row < 0) || (column >= height) || (row >= width))
            {
                continue;
            }
            else
            {
                switch (color)
                {
                    case 'b':
                        x += image[column][row].rgbtBlue * Gx[column + 1 - i][row + 1 - j];
                        y += image[column][row].rgbtBlue * Gy[column + 1 - i][row + 1 - j];
                        break;
                    case 'g':
                        x += image[column][row].rgbtGreen * Gx[column + 1 - i][row + 1 - j];
                        y += image[column][row].rgbtGreen * Gy[column + 1 - i][row + 1 - j];
                        break;
                    case 'r':
                        x += image[column][row].rgbtRed * Gx[column + 1 - i][row + 1 - j];
                        y += image[column][row].rgbtRed * Gy[column + 1 - i][row + 1 - j];
                        break;
                }
            }
        }
    }
    int result = round(sqrt(pow(x, 2) + pow(y, 2)));
    if (result > 255)
    {
        result = 255;
    }
    return result;
}