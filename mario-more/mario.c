#include <cs50.h>
#include <stdio.h>

void rightLeaningTriangle(int height);
void leftLeaningTriangle(int height);
void spaces(int height);

int main(void)
{
    int height;
    do
        {
            height = get_int("Height: ");
        }
    while (height <= 0 || height > 8);

    rightLeaningTriangle(height);
    spaces(height);
    leftLeaningTriangle(height);


}

void rightLeaningTriangle(int height)
{
    for(int i = 0; i < height; i++)
    {
        for(int space = (height - i); space > 1; space--)
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

void leftLeaningTriangle(int height)
{
    for (int i = 0; i < height; i++){
        for (int hashtag = 0; hashtag < i; hashtag++){
            printf("#");
        }


        printf("\n");
    }
}

void spaces(int height){
    for(int i = 0; i < height; i++)
    {
        printf("  ");
        printf("\n");
    }
}