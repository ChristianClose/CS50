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

        char letter = plainText[i] + key;

        if(letter > 'Z' &&  letter < 'a')
        {
            letter = 'A' + (letter - 'Z');
        }
        else if(letter > 'z'){
            letter = 'a' + (letter - 'z');
        }

        cipherText[i] = letter;
    }

    char *cipherTextPointer = cipherText;
    return cipherTextPointer;
}

