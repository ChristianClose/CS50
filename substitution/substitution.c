#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    int key = 0;
    if(argc == 2){
        if(strlen(argv[1]) == 26){
            key = atoi(argv[i]);
        } else {
            printf("Key must contain 26 characters.");
        }

    } else {
        printf("Usage: ./substitution key);
    }


}