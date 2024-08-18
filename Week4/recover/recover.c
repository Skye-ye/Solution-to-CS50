#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define BLOCK_SIZE 512

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: ./recover FILE\n");
    return 1;
  }

  FILE *file = fopen(argv[1], "r");
  if (file == NULL) {
    printf("Could not open file.\n");
    return 1;
  }

  uint8_t buffer[BLOCK_SIZE];

  while (fread(buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE) {
    if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
        (buffer[3] & 0xf0) == 0xe0) {
      char filename[8];
      static int count = 0;
      sprintf(filename, "%03i.jpg", count);
      FILE *img = fopen(filename, "w");
      if (img == NULL) {
        printf("Could not create file.\n");
        return 1;
      }
      fwrite(buffer, 1, BLOCK_SIZE, img);
      while (fread(buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE) {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0) {
          fclose(img);
          count++;
          sprintf(filename, "%03i.jpg", count);
          img = fopen(filename, "w");
          if (img == NULL) {
            printf("Could not create file.\n");
            return 1;
          }
        }
        fwrite(buffer, 1, BLOCK_SIZE, img);
      }
      fclose(img);
    }
  }
  fclose(file);
  return 0;
}