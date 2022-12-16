#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    int key = 0;
    if(argc == 2){
        if(strlen(argv[1]) == 26){
            key = atoi(argv[1]);
        } else {
            printf("Key must contain 26 characters.\n");
        }

    } else {
        printf("Usage: ./substitution key\n");
    }


}