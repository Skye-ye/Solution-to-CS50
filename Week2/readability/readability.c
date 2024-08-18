#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void) {
  string text = get_string("Text:");
  int letters = count_letters(text);
  int words = count_words(text);
  int sentences = count_sentences(text);
  float L = ((float)letters / (float)words) * 100;
  float S = ((float)sentences / (float)words) * 100;
  float index = 0.0588 * L - 0.296 * S - 15.8;
  int rounded_index = round(index);

  if (rounded_index < 1) {
    printf("Before Grade 1\n");
  } else if (rounded_index >= 16) {
    printf("Grade 16+\n");
  } else {
    printf("Grade %i\n", rounded_index);
  }
  return 0;
}

int count_letters(string text) {
  int i = 0;
  int n = 0;
  while (text[i] != '\0') {
    if (isalpha(text[i])) {
      n++;
    }
    i++;
  }
  return n;
}

int count_words(string text) {
  int i = 0;
  int n = 0;
  while (text[i] != '\0') {
    if (isblank(text[i])) {
      n++;
    }
    i++;
  }
  return n + 1;
}

int count_sentences(string text) {
  int i = 0;
  int n = 0;
  while (text[i] != '\0') {
    if (text[i] == '.' || text[i] == '?' || text[i] == '!') {
      n++;
    }
    i++;
  }
  return n;
}