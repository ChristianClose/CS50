#include <cs50.h>
#include <stdio.h>

string createTriangle(int base);

int main(void)
{
    string triangle = createTriangle(8);
    printf("%s", triangle);
}

string createTriangle(int base)
{
    string triangle = "";

    for(int i = 0; i < base; i++){
        triangle += '#';
        printf("%s", triangle);
    }

    return triangle;
}