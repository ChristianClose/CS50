#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *encrypt(int key, string plainText);

int main(int argc, string argv[])
{
    int key = 0;
    if(argc >= 2)
    {
      key = atoi(argv[1]);
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
    char cipherText[plainTextSize];

    for(int i = 0; i < strlen(plainText); i++)
    {
        char letter;
        if(plainText[i] >= 'A' && plainText[i] <= 'z'){
            letter = plainText[i] + key;
        } else {
            letter = plainText[i];
        }

        if(letter > 'Z' &&  letter < 'a')
        {
            letter = 'A' + (letter - 'Z');
        }

        if(letter > 'z')
        {
            printf("Hello \n");
            letter = 'a' + (letter - 'z');
        }

        if(letter < 'A'){
            letter = 'A';
        }

        printf("Letter: %c\n\n", letter);
       // printf("plainText[i]: %c\n", plainText[i]);


         cipherText[i] = letter;

    }

    char *cipherTextPointer = cipherText;
    return cipherTextPointer;
}

