#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int height;
    //Get Height From the User
    do
    {
        height = get_int("Height: ");
    }
    while (height <= 0 || height > 8);

    //Create main loop to create triangle
    for (int i = 0; i < height; i++)
    {
        //Add spaces to make triangle right aligned
        for (int space = (height - i); space > 1; space--)
        {
            printf(" ");
        }

        //Add hashtag to triangle
        for (int hashtag = 0; hashtag <= i; hashtag++)
        {
            printf("#");
        }


        printf("\n");
    }
}

