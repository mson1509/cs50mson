#include "helpers.h"

void swap(RGBTRIPLE* a, RGBTRIPLE* b);

int const num_color_channels = 3;
int const num_pixels_grid = 9;
int const num_pixels_edge = 6;
int const num_pixels_corner = 4;

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int gray_pixel = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed)/num_color_channels;
            image[i][j].rgbtBlue = gray_pixel;
            image[i][j].rgbtGreen = gray_pixel;
            image[i][j].rgbtRed = gray_pixel;
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
            if ((i = 0 && (j = width - 1 || j = 0)) || (i = height - 1 && (j = 0 || j = width - 1)))
            {
                image[i][j].rgbtBlue = avg(i, j, height, width, 'b', copy);
            }
            else if (i = 0 || i = height - 1 || j = 0 || j = width - 1)
            {
                image[i][j] = avg(i, j, num_pixels_edge);
            }
            else
            {
                image[i][j] = avg(i, j, num_pixels_grid);
            }
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

void swap(RGBTRIPLE* a, RGBTRIPLE* b)
{
    RGBTRIPLE temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int avg(int i, int j, int height, int width, char color, RGBTRIPLE image[column][row])
{
    int sum = 0;
    for (column = (i - 1); column <= (i + 1); column++)
    {
        for (row = (j - 1); row <= (j + 1); row++)
        {
            if ((column < 0) || (row  < 0) || (column == height) || (row == width))
            {
                continue;
            }
            else
            {
                switch (color)
                {
                    case 'b':
                        sum += copy[i][j].rgbtBlue;
                        break;
                    case 'g':
                        sum += copy[i][j].rgbtGreen;
                        break;
                    case 'r':
                        sum += copy[i][j].rgbtRed;
                        break;
                }
            }
        }
    }
    return sum;
}