#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
const int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
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

    // TODO: Print the winner
    if(score1 > score2)
    {
        printf("Player 1 wins!");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!");
    } else
    {
        printf("Tie!");
    }
}

int compute_score(string word)
{
    int score = 0;
    word = lowercase(word);

    // TODO: Compute and return score for string
    for(int i = 0; i < sizeof word; i++)
    {
        for (int j = 0; j < sizeof ALPHABET; j++)
        {
            if(word[i] == ALPHABET[j])
            {
                score += POINTS[j];
            }
        }
    }

    return score;
}

string lowercase(string word){
    for(int i = 0; i < sizeof word; i++){
        word[i] = tolower(word[i]);
    }

    return word;
}
