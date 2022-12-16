#include <cs50.h>
#include <stdio.h>
#include <string.h>

int countLetters(string text);
int countWords(string text);
bool isLetter(char letter);

int main(void)
{
    string text = get_string("Text: \n");
    int numOfLetters = countLetters(text);
    int numOfWords = countWords(text);

    printf("%i\n", numOfLetters);
    printf("%i\n", numOfWords);


}

int countLetters(string text)
{
    int count = 0;

    for(int i = 0; i < strlen(text); i++){
        if(isLetter(text[i])){
            count++;
        }
    }

    return count;
}

int countWords(string text)
{
    int count = 1;

    for(int i = 0; i < strlen(text); i++){
        if (text[i] == ' '){
            count++;
        }
    }

    return count;
}

bool isLetter(char letter){
    const int CAPITAL_LOWER_NUM = 65;
    const int CAPITAL_UPPER_NUM = 90;
    const int LOWERCASE_LOWER_NUM = 97;
    const int LOWERCASE_UPPER_NUM = 122;

    //Check if uppercase
    for(int i = CAPITAL_LOWER_NUM; i < CAPITAL_UPPER_NUM; i++){
        if (letter == i){
            return true;
        }
    }

    //Check if lowercase
    for(int i = LOWERCASE_LOWER_NUM; i < LOWERCASE_UPPER_NUM; i++){
        if(letter == i){
            return true;
        }
    }

    return false;
}