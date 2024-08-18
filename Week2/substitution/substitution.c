#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool is_valid_key(string key);

int main(int argc, string argv[]) {
  if (argc != 2) {
    printf("Usage: ./substitution key");
    return 1;
  }

  string key = argv[1];
  if (!is_valid_key(key)) {
    printf("Key must contain 26 characters.\n");
    return 1;
  }

  string plain_text = get_string("plaintext: ");
  for (int i = 0; plain_text[i] != '\0'; i++) {
    if (isalpha(plain_text[i])) {
      if (isupper(plain_text[i])) {
        plain_text[i] = toupper(key[plain_text[i] - 'A']);
      } else {
        plain_text[i] = tolower(key[plain_text[i] - 'a']);
      }
    }
  }
  printf("ciphertext: %s\n", plain_text);
  return 0;
}

bool is_valid_key(string key) {
  bool used[26] = {false};
  if (strlen(key) != 26) {
    return false;
  }
  for (int i = 0; key[i] != '\0'; i++) {
    if (!isalpha(key[i])) {
      return false;
    }
    int index = tolower(key[i]) - 'a';
    if (used[index]) {
      return false;
    }
    used[index] = true;
  }
  return true;
}