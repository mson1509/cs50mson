#include <cs50.h>
#include <stdio.h>
#include <string.h>


// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[4];

// Number of candidates
int candidate_count;

bool vote(string name);
void print_winner(void);

int main(void)
{
    candidate_count = 4;
    candidates[0].name = "bon";
    candidates[1].name = "ha";
    candidates[2].name = "tuan";
    candidates[3].name = "huong";
    for (int i = 0; i < candidate_count; i++)
    {
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
    for (int i = 0;i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name))
        {
            candidates[i].votes += 1;
            return true;
            break;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int most_votes = 0;
    int winner[candidate_count];
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > most_votes)
        {
            most_votes = candidates[i].votes;
        }
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == most_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}