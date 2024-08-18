#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void) {
  // TODO
  string s = get_string("Message:");
  int i = 0;
  while (s[i] != '\0') {
    char character = s[i];
    int n = 256 - character;
    for (int j = 0; j < BITS_IN_BYTE; j++) {
      print_bulb(n % 2);
      n /= 2;
    }
    printf("\n");
    i++;
  }
}

void print_bulb(int bit) {
  if (bit == 0) {
    // Dark emoji
    printf("\U000026AB");
  } else if (bit == 1) {
    // Light emoji
    printf("\U0001F7E1");
  }
}
