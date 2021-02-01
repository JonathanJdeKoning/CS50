#include "helpers.h"
#include <math.h>
#include <stdio.h>
//   ./filter -g images/yard.bmp out.bmp
//   check50 cs50/problems/2020/x/filter/less
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i ++)
    {
        for (int j = 0; j < width; j++)
        {
            float mean = (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0;
            int avg = round(mean);

            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
}

// Convert image to sepia
//  ./filter -s images/yard.bmp out.bmp
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i ++)
    {
        for (int j = 0; j < width; j++)
        {
            float sepiaRed = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue;
            float sepiaGreen = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue;
            float sepiaBlue = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue;

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            image[i][j].rgbtRed = round(sepiaRed);
            image[i][j].rgbtBlue = round(sepiaBlue);
            image[i][j].rgbtGreen = round(sepiaGreen);
        }
    }
}

// Reflect image horizontally
//   ./filter -r images/tower.bmp out.bmp

void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i ++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE tmp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = tmp;
        }
    }
}

// Blur image
//  ./filter -b images/tower.bmp out.bmp
void blur(int height, int width, RGBTRIPLE image[height][width])
{
//if ((i > 0 && i < height - 1) && (j > 0 && j < width - 1))
    float four = 4.0;
    float six = 6.0;
    float nine = 9.0;
    RGBTRIPLE tmp[height][width];
    for (int i = 0; i < height; i ++)
    {
        for (int j = 0; j < width; j++)
        {

            if (i == 0 && j == 0)   //Bottom Left
            {
                tmp[i][j].rgbtRed = round(((image[i][j].rgbtRed + image[i + 1][j].rgbtRed + image[i][j + 1].rgbtRed + image[i +
                                            1][j + 1].rgbtRed) / four));
                tmp[i][j].rgbtGreen = round(((image[i][j].rgbtGreen + image[i + 1][j].rgbtGreen + image[i][j + 1].rgbtGreen +
                                              image[i + 1][j + 1].rgbtGreen) / four));
                tmp[i][j].rgbtBlue = round(((image[i][j].rgbtBlue + image[i + 1][j].rgbtBlue + image[i][j + 1].rgbtBlue + image
                                             [i + 1][j + 1].rgbtBlue) / four));
            }
            else if (i == 0 && j == width - 1)    //Bottom Right
            {
                tmp[i][j].rgbtRed = round(((image[i][j].rgbtRed + image[i + 1][j].rgbtRed + image[i][j - 1].rgbtRed + image[i +
                                            1][j - 1].rgbtRed) / four));
                tmp[i][j].rgbtGreen = round(((image[i][j].rgbtGreen + image[i + 1][j].rgbtGreen + image[i][j - 1].rgbtGreen + image
                                              [i + 1][j - 1].rgbtGreen) / four));
                tmp[i][j].rgbtBlue = round(((image[i][j].rgbtBlue + image[i + 1][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i
                                             + 1][j - 1].rgbtBlue) / four));
            }
            else if (i == height - 1 && j == 0)   //Top Left
            {
                tmp[i][j].rgbtRed = round(((image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i][j + 1].rgbtRed + image[i -
                                            1][j + 1].rgbtRed) / four));
                tmp[i][j].rgbtGreen = round(((image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i][j + 1].rgbtGreen + image
                                              [i - 1][j + 1].rgbtGreen) / four));
                tmp[i][j].rgbtBlue = round(((image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i -
                                             1][j + 1].rgbtBlue) / four));
            }
            else if (i == height - 1 && j == width - 1)   //Top Right
            {
                tmp[i][j].rgbtRed = round(((image[i][j].rgbtRed + image[i - 1][j].rgbtRed + image[i][j - 1].rgbtRed + image[i - 1]
                                            [j - 1].rgbtRed) / four));
                tmp[i][j].rgbtGreen = round(((image[i][j].rgbtGreen + image[i - 1][j].rgbtGreen + image[i][j - 1].rgbtGreen + image
                                              [i - 1][j - 1].rgbtGreen) / four));
                tmp[i][j].rgbtBlue = round(((image[i][j].rgbtBlue + image[i - 1][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i -
                                             1][j - 1].rgbtBlue) / four));
            }
            else if ((j > 0 && j < width) && i == height - 1)     //Top Edge
            {
                tmp[i][j].rgbtGreen = round(((image[i][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i - 1][j + 1].rgbtGreen
                                              + image[i - 1][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i][j + 1].rgbtGreen) / six));
                tmp[i][j].rgbtRed = round(((image[i][j].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i
                                            - 1][j].rgbtRed + image[i][j - 1].rgbtRed + image[i][j + 1].rgbtRed) / six));
                tmp[i][j].rgbtBlue = round(((image[i][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i - 1][j + 1].rgbtBlue +
                                             image[i - 1][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i][j + 1].rgbtBlue) / six));
            }
            else if ((j > 0 && j < width) && i == 0)  //Bottom Edge
            {
                tmp[i][j].rgbtGreen = round(((image[i][j].rgbtGreen + image[i][j - 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen +
                                              image[i + 1][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / six));
                tmp[i][j].rgbtBlue = round(((image[i][j].rgbtBlue + image[i][j - 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image
                                             [i + 1][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / six));
                tmp[i][j].rgbtRed = round(((image[i][j].rgbtRed + image[i][j - 1].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i +
                                            1][j].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j + 1].rgbtRed) / six));
            }
            else if ((i > 0 && i < height) && j == 0)     //Left Edge
            {
                tmp[i][j].rgbtGreen = round(((image[i][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i - 1][j].rgbtGreen +
                                              image[i + 1][j].rgbtGreen + image[i][j + 1].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / six));
                tmp[i][j].rgbtBlue = round(((image[i][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i - 1][j].rgbtBlue + image
                                             [i + 1][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / six));
                tmp[i][j].rgbtRed = round(((image[i][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i - 1][j].rgbtRed + image[i +
                                            1][j].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j + 1].rgbtRed) / six));
            }
            else if ((i > 0 && i < height) && j == width - 1)     //Right Edge
            {
                tmp[i][j].rgbtBlue = round(((image[i][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image[
                                                 i][j - 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue) / six));
                tmp[i][j].rgbtGreen = round(((image[i][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen +
                                              image[i][j - 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen) / six));
                tmp[i][j].rgbtRed = round(((image[i][j].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i][j
                                            - 1].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed) / six));
            }
            else    //Middle
            {
                tmp[i][j].rgbtGreen = round(((image[i][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen +
                                              image[i][j - 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i][j + 1].rgbtGreen +
                                              image[i + 1][j + 1].rgbtGreen + image[i - 1][j + 1].rgbtGreen) / nine));
                tmp[i][j].rgbtBlue = round(((image[i][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue + image
                                             [i][j - 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i][j + 1].rgbtBlue + image[i
                                                     + 1][j + 1].rgbtBlue + image[i - 1][j + 1].rgbtBlue) / nine));
                tmp[i][j].rgbtRed = round(((image[i][j].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed + image[i]
                                            [j - 1].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i][j + 1].rgbtRed + image[i + 1][j
                                                    + 1].rgbtRed + image[i - 1][j + 1].rgbtRed) / nine));
            }
        }
    }
    for (int k = 0; k < height; k++)
    {
        for (int l = 0; l < width; l++)
        {
            image[k][l] = tmp[k][l];
        }
    }
}