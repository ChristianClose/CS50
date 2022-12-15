#include <cs50.h>
#include <stdio.h>

char createTriangle(int base);

int main(void)
{
    char triangle[100] = createTriangle(8);
    printf("%s\n", triangle);
}

char createTriangle(int base)
{
    char triangle[100] = "";

    for(int i = 0; i < base; i++){
        triangle += '#';
        triangle += '\n';
        printf("%i\n", i);
        printf("%s\n", triangle);
    }

    return triangle;
}