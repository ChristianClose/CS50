#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int height = get_int("Height: ");

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < i; j++)
        {
           printf("#");
        }

        for(int k = (i-1); k > 0; k--){
            printf(" ");
        }

        printf("\n");
    }
}

