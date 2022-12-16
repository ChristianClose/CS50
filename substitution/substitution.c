#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *encrypt(string key, string plaintext);
char *getAlphabet(string caseType);
char *lowercase(string word);
string validateKey(string key);

int main(int argc, string argv[])
{
    string key = 0;

    if(argc == 2)
    {
        string isValidKey = validateKey(argv[1]);
        if(strcmp(isValidKey,"OK") == 0){
            key = lowercase(argv[1]);
        }
        else if(strcmp(isValidKey,"lengthError") == 0){
            printf("Key must contain 26 characters.\n");
            return 1;
        } else if(strcmp(isValidKey,"invalidChar") == 0){
            printf("Invalid characters found in key.\n");
            return 1;
        }
        else
        {
            printf("Duplicate characters found in key. \n");
            return 1;
        }

    } else {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");

    string ciphertext = encrypt(key, plaintext);
    printf("ciphertext: %s\n", ciphertext);
}

char *encrypt(string key, string plaintext)
{
    char *alphabetLower = getAlphabet("lower");
    char *alphabetUpper = getAlphabet("upper");
    char *ciphertext = (char*) malloc(strlen(plaintext) * sizeof(char));

    for(int i = 0; i < strlen(plaintext); i++)
    {
        if(islower(plaintext[i]) > 0){
            for(int j = 0; j < strlen(alphabetLower); j++)
            {
                if (plaintext[i] == alphabetLower[j])
                {
                    printf("Hello!");
                    ciphertext[i] = key[j];
                    continue;
                }
            }
        }
        else if(isupper(plaintext[i]) > 0)
        {
            for (int j = 0; j < strlen(alphabetUpper); j++)
            {
                if(plaintext[i] == alphabetUpper[j]){

                    ciphertext[i] = toupper(key[j]);
                    continue;
                }

            }
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }

    }

    return ciphertext;
}

char *getAlphabet(string caseType)
{
    int alphabetSize = 27;
    char *alphabet = (char*) malloc(alphabetSize * sizeof(char));
    int count = 0;

    if(strcmp(caseType, "lower") == 0)
    {
        for(char i = 'a'; i <= 'z'; i++)
        {
            alphabet[count] = i;
            count++;
        }
    }
    else
    {
        for(char i = 'A'; i <= 'Z'; i++ )
        {
            alphabet[count] = i;
            count++;
        }
    }

    return alphabet;
}


char *lowercase(string word)
{
    string lowercaseWord = (char*) malloc(strlen(word) * sizeof(char));
    for(int i = 0; i < strlen(word); i++)
    {
        lowercaseWord[i] = tolower(word[i]);
    }

    return lowercaseWord;
}

//Returns 0 if dulicate,
//returns -1 if incorrect length
//returns -2 if invalid character
//returns 1 if valid
string validateKey(string key)
{
    printf("%lu\n", strlen(key));
    if(strlen(key) == 26)
    {
       for(int i = 0; i< strlen(key); i++)
       {
            for(int j = 1; j < strlen(key); j++)
            {
                if(j == i){
                    j++;
                }

                if(key[i] == key[j]){
                    return "duplicateError";
                }

                //check if character is not in the alphabet
                if((key[j] > 'Z' && key[j] < 'a') || key[j] > 'z' || key[j] < 'A')
                {
                    return "invalidChar";
                }
            }
    }
    }
    else
    {
        return "lengthError";
    }

    return "OK";
}
