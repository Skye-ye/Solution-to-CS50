#include <cs50.h>
#include <stdio.h>

void print_grid(int n, int m);

int main(void) {
  int height;
  do {
    height = get_int("Height: ");
  } while (height > 9 || height < 1);
  print_grid(height, height);
  return 0;
}

void print_grid(int n, int m) {
  if (n < 1) {
    return;
  }
  print_grid(n - 1, m);
  int blank_count = m - n;
  for (int i = 0; i < blank_count; i++) {
    printf(" ");
  }
  for (int i = 0; i < n; i++) {
    printf("#");
  }
  printf("  ");
  for (int i = 0; i < n; i++) {
    printf("#");
  }
  printf("\n");
}