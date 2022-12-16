#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* encrypt(int key, string plainText);

int main(int argc, string argv[])
{
    int key = atoi(argv[1]);
    string plainText = get_string("plaintext: ");
    char* cipherText = cipherText = encrypt(key, plainText);

    printf("plaintext: %s\n", plainText);
    printf("ciphertext: %s\n", cipherText);
    printf("key: %i\n", key);

}

char* encrypt(int key, string plainText)
{

    int plainTextSize = (int)strlen(plainText);
    char cipherText[plainTextSize];
    //string cipherText = "";
    //char cipherText*;

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

        printf("%c\n", letter);


        cipherText[i] = letter;
    }

    printf("%s\n", cipherText);

    return cipherText;
}

