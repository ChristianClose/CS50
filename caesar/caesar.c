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
    printf("key: %i\n", key);
    printf("ciphertext: %s\n", cipherText);
}

char *encrypt(int key, string plainText)
{

    //Get the size of the plainText and create an array with its size
    int plainTextSize = (int)strlen(plainText);
    char cipherText[plainTextSize + 1];

    for (int i = 0; i < strlen(plainText); i++)
    {
        int letter;
        //Check if plainText is a valid letter and set letter
        if (plainText[i] >= 'A' && plainText[i] <= 'z')
        {
            letter = plainText[i] + key;
        }
        else
        {
            letter = plainText[i];
        }


        //If the letter is greater than capital 'Z', and less than 'a'
        //then the orginal letter must have been Uppercase
        //Therefore, set the letter to the first letter of the alphabet ('A')
        //and add that value to the value of letter - the value of 'Z'
        // Then subtract 1 to get the right ASCII num
        if (letter > 'Z' &&  letter < 'a')
        {
            letter = 'A' + (letter - 'Z') - 1;
        }

        if (letter > 'z')
        {
            letter = 'a' + (letter - 'z') - 1;
            //Keep looping thru the alphabet and modifying letter, just incase
            //letter is significantly higher than ASCII num for 'z'
            for (int j = 'a'; j < 'z'; j++)
            {
                if (letter > 'z')
                {
                    letter = 'a' + (letter - 'z') - 1;
                }
            }

        }

        printf("");

        cipherText[i] = letter;
    }

    //Terminate String
    cipherText[plainTextSize] = '\0';

    //Only way to pass an array is as a pointer
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

