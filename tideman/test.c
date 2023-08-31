#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count = 3;
int candidate_count = 3;

void lock_pair(void);

int main(void)
{
pairs[0].winner = 0;
pairs[0].loser = 1;
pairs[1].winner = 2;
pairs[1].loser = 0;
pairs[2].winner = 1;
pairs[2].loser = 2;
}

void lock_pairs(void)
{
    for (int x = 0; x < pair_count; x++)
    {
        locked[pairs[x].winner][pairs[x].loser] = true;
        //check if cycle was created
        for (int i = 0; i < candidate_count; i++)
        {
            for (int j = 0; j < candidate_count; j++)
            {
                if (locked[j][i])
                {
                    break;
                }
                //if there is still a source, keep lock pairs
                else if (j == candidate_count - 1)
                {
                    i = MAX + 1;
                }
            }
            // if there is no source left, unlock the last pair
            if (i == candidate_count - 1)
            {
                locked[pairs[x].winner][pairs[x].loser] = false;
            }
        }
    }
    return;
}