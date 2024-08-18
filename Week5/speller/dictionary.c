// Implements a dictionary's functionality

#include "dictionary.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node {
  char word[LENGTH + 1];
  struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 100003;

// Hash table
node *table[N];

unsigned int word_count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word) {
  // TODO
  unsigned int index = hash(word);
  node *n = table[index];
  while (n != NULL) {
    if (strcasecmp(n->word, word) == 0) {
      return true;
    }
    n = n->next;
  }
  return false;
}

// Hashes word to a number
unsigned int hash(const char *word) {
  // TODO: Improve this hash function
  unsigned int hash_val = 0;
  unsigned int prime = 31;
  unsigned int power = 1;

  for (int i = 0; word[i] != '\0'; i++) {
    if (word[i] == '\'') {
      hash_val += 27 * power;
    } else {
      hash_val += (tolower(word[i]) - 'a' + 1) * power;
    }
    power *= prime;
  }

  return hash_val % N;
}

bool insert(const char *word) {
  unsigned int index = hash(word);
  node *n = malloc(sizeof(node));
  if (n == NULL) {
    return false;
  }
  strcpy(n->word, word);
  n->next = table[index];
  table[index] = n;
  return true;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary) {
  // TODO
  FILE *source = fopen(dictionary, "r");
  if (source == NULL) {
    printf("Failed to open dictionary.\n");
    return false;
  }

  char word[LENGTH + 1];
  while (fscanf(source, "%s", word) != EOF) {
    if (!insert(word)) {
      printf("Failed to insert word into hash table.\n");
      fclose(source);
      return false;
    }
    word_count++;
  }

  fclose(source);
  return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void) {
  // TODO
  return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void) {
  // TODO
  for (int i = 0; i < N; i++) {
    node *n = table[i];
    while (n != NULL) {
      node *tmp = n;
      n = n->next;
      free(tmp);
    }
    table[i] = NULL;
  }
  return true;
}
