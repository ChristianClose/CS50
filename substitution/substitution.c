#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

char *encrypt(string key, string plaintext);
char *getAlphabet(string caseType);
char *lowercase(string word);
bool validateKey(string key);

int main(int argc, string argv[])
{
    string key = 0;
    if(argc == 2){
        if(validateKey(argv[1])){
            key = lowercase(argv[1]);
        } else {
            printf("Key must contain 26 characters.\n");
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

bool validateKey(string key)
{
    if(strlen(key) == 26)
    {
        int duplicates = 0;
        for(int i = 0; i < strlen(key); i++)
        {
            for(int j = 1; j < strlen(key) - 1; j++)
            {
                if(key[i] == key[j]){
                    return false;
                }
            }
        }
    }

    return true;
}
