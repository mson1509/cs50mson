// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"

// define the starting number of lower alphabetical character in ASCII
#define LOWER_ASCII = 97;
#define ALPHABET_LETTERS = 26;
// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = ALPHABET_LETTERS * 10000 + ALPHABET_LETTERS * 100 + LENGTH;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    unsigned int hashcode = hash(word);
    if (table[hashcode]->next == NULL)
    {
        return false;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int length = strlen(word) - 1;
    unsigned int first_letter = word[0];
    unsigned int last_letter = word[length - 1];
    if (isupper(first_letter))
    {
        first_letter = tolower(first_letter);
    }
    if (isupper(last_letter))
    {
        last_letter = tolower(last_letter);
    }
    first_letter -= LOWER_ASCII;
    last_letter -= LOWER_ASCII;
    unsigned int hashcode = last_letter * 10000 + first_letter * 100 + length;
    return hashcode;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO

    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
