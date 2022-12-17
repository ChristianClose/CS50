#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO

    for(int i = 0; i < candidate_count; i++)
    {
        if(strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    candidate winner = candidates[0];
    candidate tie[candidate_count];
    int tieCount = 0;

    for(int i = 0; i < candidate_count; i++)
    {
            printf("%s %i\n", candidates[i].name, candidates[i].votes);
            if(winner.votes > candidates[i].votes)
            {
                winner = candidates[i];
            }
            else if(winner.votes == candidates[i].votes)
            {
                tie[tieCount] = candidates[i];
                tieCount++;
            }
    }

    for(int i = 0; i < tieCount; i++)
    {
        if(tie[i].votes > winner.votes)
        {
            winner = tie[i];
            tie[i] = tie[i+1];
        } else {
            tie[i] = tie[i+1];
        }

    }

    if(tieCount == 0){
        printf("%s\n", winner.name);
    } else {
        printf("%s\n", winner.name);
        for(int i = 0; i <= tieCount; i++)
        {
            if(tie[i] != NULL){
                printf("%s\n", tie[i].name);
            }

        }
    }

    return;
}