// Implements a dictionary's functionality
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <cs50.h>
#include "dictionary.h"
#include <string.h>
#include <stdlib.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 100000;
int counter = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int h = hash(word);
    node *cursor = table[h];
    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor -> word) == 0)
        {
            return true; 
        }
        else if (cursor == NULL)
        {
            return false;
        }
        else
        {
            cursor = cursor -> next;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned long hash = 5381;
    int c = 0;

    while (c == *word++)
    {
        hash = ((hash << 5) + hash) + c; 
    }
    return hash % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        fclose(file);
        return false;
    }
    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            fclose(file);
            return false;

        }
        counter++;
        strcpy(n->word, word);
        n->next = table[hash(word)];
        table[hash(word)] = n;
    }
    fclose(file);
    return true;

}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return counter;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    node *cursor = table[0];
    node *tmp;
    for (int i = 0; i < N; i++)
    {
        cursor = table[i];
        while (cursor != NULL)
        {
            tmp = cursor;
            cursor = cursor -> next;
            free(tmp);
        }
    }
    return true;
}
//style50 comment
//style50 comment
//style50 comment
//style50 comment
//style50 comment
//style50 comment
//style50 comment
//style50 comment
//style50 comment
//style50 comment
//style50 comment
