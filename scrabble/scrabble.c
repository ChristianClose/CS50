#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
const int POINTS[] =     {1,  3,  3,  2,  1,  4,  2,  4,  1,  8,  5,  1,  3,  1,  1,  3, 10,  1,  1,  1,  1,  4,  4,  8,  4, 10};
const char ALPHABET[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

int compute_score(string word);
string lowercase(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    if(score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    } else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    int score = 0;
    word = lowercase(word);
    size_t alphabetLength = sizeof(ALPHABET) / sizeof (ALPHABET[0]);

    printf("%lu\n", alphabetLength);
    printf("%lu\n", strlen(ALPHABET));

    for(int i = 0; i < strlen(word); i++)
    {
        for (int j = 0; j < strlen(ALPHABET); j++)
        {
            if(word[i] == ALPHABET[j])
            {
                score += POINTS[i];
            }
        }
    }

    return score;
}

string lowercase(string word){
    for(int i = 0; i < strlen(word); i++){
        word[i] = tolower(word[i]);
    }

    return word;
}
