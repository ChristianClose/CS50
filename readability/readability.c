#include <cs50.h>
#include <stdio.h>
#include <string.h>

int countLetters(string text);
int countWords(string text);
int countSentences(string text);
int averageLetters(string text);
bool isLetter(char letter);

int main(void)
{
    string text = get_string("Text: \n");
    int numOfLetters = countLetters(text);
    int numOfWords = countWords(text);
    int numOfSentences = countSentences(text);
    int avgNumLetters = numOfLetters / 100;
    int avgNumSentences = numOfSentences / 100;
    int gradeLevel = 0.0588 * avgNumLetters - 0.296 * avgNumSentences - 15.8;

    printf("%i\n", numOfLetters);
    printf("%i\n", numOfWords);
    printf("%i\n", numOfSentences);
    printf("Grade Level: %i\n", gradeLevel);
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

int countSentences(string text)
{
    int count = 0;

    for(int i = 0; i < strlen(text); i++){
        switch (text[i])
        {
            case '.':
            case '!':
            case '?':
                count++;
                break;
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
    for(int i = CAPITAL_LOWER_NUM; i <= CAPITAL_UPPER_NUM; i++){
        if (letter == i){
            return true;
        }
    }

    //Check if lowercase
    for(int i = LOWERCASE_LOWER_NUM; i <= LOWERCASE_UPPER_NUM; i++){
        if(letter == i){
            return true;
        }
    }

    return false;
}