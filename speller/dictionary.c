// Implements a dictionary's functionality
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// define the starting number of lower alphabetical character in ASCII
#define LOWER_ASCII 97
#define ALPHABET_LETTERS 26
// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = (ALPHABET_LETTERS + 1) * 10000 + (ALPHABET_LETTERS + 1) * 100 + LENGTH + 1;

// global variable to keep count of words loaded
unsigned int count = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    unsigned int hashcode = hash(word);
    node *n = table[hashcode];
    while (n != NULL)
    {
        if (strcasecmp(n->word, word) == 0)
        {
            return true;
        }
        n = n->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int length = strlen(word);
    char first_letter = word[0];
    char last_letter = word[length - 1];
    if (isupper(first_letter))
    {
        first_letter = tolower(first_letter);
    }
    if (isupper(last_letter))
    {
        last_letter = tolower(last_letter);
    }
    if (first_letter == '\'')
    {
        first_letter = ALPHABET_LETTERS + LOWER_ASCII + 1;
    }
    if (last_letter == '\'')
    {
        last_letter = ALPHABET_LETTERS + LOWER_ASCII + 1;
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
    FILE *ptr = fopen(dictionary, "r");
    if (ptr == NULL)
    {
        printf("Cannot open file\n");
        return false;
    }
    char *word = malloc(sizeof(char) * (LENGTH + 1));
    if (word == NULL)
    {
        printf("Error allocating memory\n");
        fclose(ptr);
        return false;
    }
    while (fscanf(ptr, "%s", word) == 1)
    {
        unsigned int hashcode = hash(word);
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Cannot allocate memory to load word\n");
            free(word);
            fclose(ptr);
            return false;
        }
        strcpy(n->word, word);
        n->next = table[hashcode];
        table[hashcode] = n;
        count++;
    }
    free(word);
    fclose(ptr);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *n = table[i];
        while (n != NULL)
        {
            node *tmp = n;
            n = n->next;
            free(tmp);
        }
    }
    return true;
}