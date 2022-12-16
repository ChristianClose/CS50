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

    for(int i = 'A'; i < 'z'; i++){
        for(int j = 0; j < strlen(plainText); j++)
        {
            
        }

        if(i > 'Z' && i < 'a'){
            i='A';
        }

        char letter = i + key;
        printf("letter: %c\n", letter);

        if((letter > 'Z' && letter < 'a')){
        i = 'A';
        } else if (letter > 'z'){
            i = 'a';
        }


        cipherText += letter;

    }

    return cipherText;
}

