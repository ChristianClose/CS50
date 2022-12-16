#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

string encrypt(int key, string plainText);

int main(int argc, string argv[])
{
    int key = atoi(argv[0]);
    string plainText = get_string("plaintext: ");

}

string encrypt(int key, string plainText)
{
    string cipherText = "";

    for(int i = 'a'; i < 'Z'; i++){
        if(i > 'z' && i < 'A'){
            i='a';
        }

        char letter = i + key;

        if((letter > 'z' && letter < 'A')){
           i = 'a';
        } else if (letter > 'Z'){
            i = "A";
        }

    }
}

