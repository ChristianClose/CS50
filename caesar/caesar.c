#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *encrypt(int key, string plainText);
bool only_digits(string s);

int main(int argc, string argv[])
{
    int key = 0;

    //check if there are arguments and if they are valid
    if (argc >= 2 && only_digits(argv[1]))
    {
        key = atoi(argv[1]);
    }

    if (key <= 0)
    {
        printf("USAGE: ./caesar key \n");
        return 1;
    }

    if (argc < 2 || argc > 2)
    {
        printf("USAGE: ./caesar key \n");
        return 1;
    }

    string plainText = get_string("plaintext: ");
    char *cipherText = cipherText = encrypt(key, plainText);

    printf("ciphertext: %s\n", cipherText);
    printf("key: %i\n", key);

}

char *encrypt(int key, string plainText)
{

    int plainTextSize = (int)strlen(plainText);
    char cipherText[plainTextSize + 1];

    for (int i = 0; i < strlen(plainText); i++)
    {
        int letter;
        if (plainText[i] >= 'A' && plainText[i] <= 'z')
        {
            letter = plainText[i] + key;
        }
        else
        {
            letter = plainText[i];
        }

        if (letter > 'Z' &&  letter < 'a')
        {
            letter = 'A' + (letter - 'Z') - 1;
        }

        if (letter > 'z')
        {
            letter = 'a' + (letter - 'z') - 1;
            for (int j = 'a'; j < 'z'; j++)
            {
                if (letter > 'z')
                {
                    letter = 'a' + (letter - 'z') - 1;
                }
            }

        }

        cipherText[i] = letter;
    }

    cipherText[plainTextSize] = '\0';

    char *cipherTextPointer = cipherText;

    return cipherTextPointer;
}

bool only_digits(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }

    }
    return true;
}

