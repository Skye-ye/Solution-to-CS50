#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool is_valid_number(string key);

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: ./caeser key\n");
    return 1;
  }
  string key = argv[1];
  if (!is_valid_number(key)) {
    printf("Key must be a number.\n");
    return 1;
  }
  int k = atoi(key);
  string plain_text = get_string("plaintext: ");
  for (int i = 0; plain_text[i] != '\0'; i++) {
    if (isalpha(plain_text[i])) {
      if (isupper(plain_text[i])) {
        plain_text[i] = 'A' + (plain_text[i] - 'A' + k) % 26;
      } else {
        plain_text[i] = 'a' + (plain_text[i] - 'a' + k) % 26;
      }
    }
  }
  printf("ciphertext: %s\n", plain_text);
  return 0;
}

bool is_valid_number(string key) {
  for (int i = 0; key[i] != '\0'; i++) {
    if (!isdigit(key[i])) {
      return false;
    }
  }
  return true;
}