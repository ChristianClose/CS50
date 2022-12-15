#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
        {
            height = get_int("Height: ");
        }
    while (height <= 0 || height > 8);

    for(int i = 0; i < height; i++)
    {
        for(int space = (height - 1); space > 1; space--)
        {
            printf(" ");
        }

        for(int hashtag = 0; hashtag <= i; hashtag++)
        {
            printf("#");
        }
        printf("\n");
    }

}