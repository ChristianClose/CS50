#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *encrypt(string key, string plaintext);

int main(int argc, string argv[])
{
    string key = 0;
    if(argc == 2){
        if(strlen(argv[1]) == 26){
            key = argv[1];
        } else {
            printf("Key must contain 26 characters.\n");
        }

    } else {
        printf("Usage: ./substitution key\n");
    }

    string plaintext = get_string("plaintext: ");
}

char *encrypt(string key, string plaintext)
{

}