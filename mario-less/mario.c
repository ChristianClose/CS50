#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while(height <= 0 || height > 8);

    //printf("Stored: %i", height);

    for(int i = 0; i < height; i++)
    {
        for(int space = (height - i); space > 1; space--){
            printf(" ");
        }

        for(int hashtag = 0; hashtag <= i; hashtag++)
        {
           printf("#");
        }


        printf("\n");
    }
}

