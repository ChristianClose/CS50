#include "helpers.h"
#include <stdbool.h>
#include <stdio.h>

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            bool isBlackPixel = image[i][j].rgbtBlue == 0 && image[i][j].rgbtGreen == 0 &&
                                image[i][j].rgbtRed == 0;
            if (isBlackPixel)
            {
                image[i][j].rgbtBlue = 255;
                image[i][j].rgbtGreen = 0;
                image[i][j].rgbtRed = 0;
            }

        }
    }
}
