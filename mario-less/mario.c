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

    printf("Stored: %i", height);

    for(int i = 0; i < height; i++)
    {
        for(int k = (height - i); k > 0; k--){
            printf(" ");
        }

        for(int j = 0; j < i; j++)
        {
           printf("#");
        }


        printf("\n");
    }
}

