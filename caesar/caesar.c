#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *encrypt(int key, string plainText);

int main(int argc, string argv[])
{
    int key = 0;
    if(argc >= 2)
    {
      key = atoi(argv[1]);
    } else if(!isdigit(argv[1]))
    {
        printf("Usage: ./caesar key")
    }
    printf("key: %i\n", key);
    string plainText = get_string("plaintext: ");
    char* cipherText = cipherText = encrypt(key, plainText);

    printf("plaintext: %s\n", plainText);
    printf("ciphertext: %s\n", cipherText);

}

char *encrypt(int key, string plainText)
{

    int plainTextSize = (int)strlen(plainText);
    char cipherText[plainTextSize+1];

    for(int i = 0; i < strlen(plainText); i++)
    {
        int letter;
        if(plainText[i] >= 'A' && plainText[i] <= 'z'){
            letter = plainText[i] + key;
        } else {
            letter = plainText[i];
        }

        if(letter > 'Z' &&  letter < 'a')
        {
            letter = 'A' + (letter - 'Z') - 1;
        }

        if(letter > 'z')
        {
            printf("Hello \n");
            letter = 'a' + (letter - 'z') - 1;
        }

        printf("plainText Letter value: %d\n", plainText[i]);
        printf("plainText Letter: %c\n\n", plainText[i]);

        printf("Letter Value: %d\n", letter);
        printf("Letter: %c\n\n", letter);
       // printf("plainText[i]: %c\n", plainText[i]);


         cipherText[i] = letter;
    }

    cipherText[plainTextSize] = '\0';

    char *cipherTextPointer = cipherText;

    return cipherTextPointer;
}

