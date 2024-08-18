#include <cs50.h>
#include <stdio.h>

int number_length;

bool check(long number);

int main(void) {
  long number = get_long("Number: ");
  int number_length = 0;
  if (check(number)) {
    while (number >= 100) {
      number /= 10;
      number_length++;
    }
    number_length += 2;
    int code = number;
    if ((code == 34 || code == 37) && number_length == 15) {
      printf("AMEX\n");
    } else if (code >= 51 && code <= 55 && number_length == 16) {
      printf("MASTERCARD\n");
    } else if (code >= 40 && code <= 49 &&
               (number_length == 13 || number_length == 16)) {
      printf("VISA\n");
    } else {
      printf("INVALID\n");
    }
  } else {
    printf("INVALID\n");
  }
  return 0;
}

bool check(long number) {
  int sum = 0;
  bool alternate = false;

  while (number > 0) {
    int digit = number % 10;
    if (alternate) {
      digit *= 2;
      if (digit > 9) {
        digit = digit % 10 + 1;
      }
    }
    sum += digit;
    number /= 10;
    alternate = !alternate;
  }

  return sum % 10 == 0;
}