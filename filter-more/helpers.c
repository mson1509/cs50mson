#include "helpers.h"

void swap(RGBTRIPLE* a, RGBTRIPLE* b);
RGBTRIPLE avg(int i, int j, int num_pixels);

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
            if ((i = 0 && (j = width - 1 || j = 0)) || (i = height - 1 && (j = 0 || j = width - 1))
            {
                image[i][j] = avg(i, j, num_pixels_corner);
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

RGBTRIPLE avg(int i, int j, int num_pixels)
{
    int total = 0;
    int a = i + 1;
    int b = i - 1;
    int c = j + 1;
    int d = j - 1;
    switch (i)
    {
        case 0:
            total = total + image[i][j].rgbtBlue + image[i][c].rgbtBlue + image[i][d].rgbtBlue;
            total = total + image[a][j].rgbtBlue + image[a][c].rgbtBlue + image[a][d].rgbtBlue;
            break;
        case height - 1:
            total = total + image[i][j].rgbtBlue + image[i][c].rgbtBlue + image[i][d].rgbtBlue;
            total = total + image[b][j].rgbtBlue + image[b][c].rgbtBlue + image[b][d].rgbtBlue;
            break;
    }
    switch (j)
    {
        case 0:
            total = total + image[i][j].rgbtBlue + image[a][j].rgbtBlue + image[b][j].rgbtBlue;
            total = total + image[i][c].rgbtBlue + image[a][c].rgbtBlue + image[b][c].rgbtBlue;
            break;
        // if j = width - 1
        case width - 1:
            total = total + image[i][j].rgbtBlue + image[a][j].rgbtBlue + image[b][j].rgbtBlue;
            total = total + image[i][d].rgbtBlue + image[a][d].rgbtBlue + image[b][d].rgbtBlue;
            break;
    }
    if (num_pixels == 4)
    {
        switch (i + j)
        {
            case 0:
                total -= image[i][j].rgbtBlue;
                break;
            case height - 1:
                total -= image[a][d].rgbtBlue;
                break;
            case width - 1:
                total -= image[b][c].rgbtBlue;
                break;
            case height + width - 2:
                total -= image[a][c].rgbtBlue;
                break;
        }
    }

    total = total + image[i][j].rgbtBlue + image[i][c].rgbtBlue + image[i][d].rgbtBlue;
    total = total + image[a][j].rgbtBlue + image[a][c].rgbtBlue + image[a][d].rgbtBlue;
    total = total + image[b][j].rgbtBlue + image[b][c].rgbtBlue + image[b][d].rgbtBlue;
}