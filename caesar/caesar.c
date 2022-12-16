#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

string encrypt(int key, string plainText);

int main(int argc, string argv[])
{
    int key = atoi(argv[0]);
    string plainText = get_string("plaintext: ");
    string cipherText = encrypt(key, plainText);

    printf("plaintext: %s\n", plainText);
    printf("ciphertext: %s\n", cipherText);

}

string encrypt(int key, string plainText)
{
    string cipherText = "";

    for(int i = 0; i < strlen(plainText); i++){
        char letter = plainText[i];

        if(letter > 'Z' && < 'a')
        {
            letter = 'A' + (letter - 'Z');
        }
        else if(letter > 'z'){
            letter = 'a' + (letter - "z");
        }

        cipherText += letter;
    }

    return cipherText;
}

