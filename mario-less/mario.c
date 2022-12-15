#include <cs50.h>
#include <stdio.h>

string createTriangle(int base);

int main(void)
{
    string triangle = createTriangle(8);
    printf("%s\n", triangle);
}

string createTriangle(int base)
{
    string triangle = "";

    for(int i = 0; i < base; i++){
        triangle += '#';
        triangle += '\n';
        printf("%i\n", i);
        printf("%s\n", triangle);
    }

    return triangle;
}