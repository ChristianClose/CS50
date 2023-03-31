#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
struct score_map
{
    char key;
    int value;
};


const struct score_map POINTS_MAP[28] =
{
    {'a', 1},
    {'b', 3},
    {'c', 3},
    {'d', 2},
    {'e', 1},
    {'f', 4},
    {'g', 2},
    {'h', 4},
    {'i', 1},
    {'j', 8},
    {'k', 5},
    {'l', 1},
    {'m', 3},
    {'n', 1},
    {'o', 1},
    {'p', 3},
    {'q', 10},
    {'r', 1},
    {'s', 1},
    {'t', 1},
    {'u', 1},
    {'v', 4},
    {'w', 4},
    {'x', 8},
    {'y', 4},
    {'z', 10}
};


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

    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    int score = 0;
    word = lowercase(word);
    size_t alphabetLength = sizeof(POINTS_MAP) / sizeof(POINTS_MAP[0]);

    for (int i = 0; i < alphabetLength; i++)
    {
        for (int j = 0; j < strlen(word); j++)
        {
            if (word[j] == POINTS_MAP[i].key)
            {
                score += POINTS_MAP[i].value;
            }
        }
    }

    return score;
}

string lowercase(string word)
{
    for (int i = 0; i < strlen(word); i++)
    {
        word[i] = tolower(word[i]);
    }

    return word;
}
