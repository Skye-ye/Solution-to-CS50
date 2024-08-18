#include "helpers.h"

#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width]) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      RGBTRIPLE pixel = image[i][j];
      int average =
          round((pixel.rgbtRed + pixel.rgbtGreen + pixel.rgbtBlue) / 3.0);
      image[i][j].rgbtRed = average;
      image[i][j].rgbtGreen = average;
      image[i][j].rgbtBlue = average;
    }
  }
  return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width]) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      RGBTRIPLE pixel = image[i][j];
      int sepiaRed = round(.393 * pixel.rgbtRed + .769 * pixel.rgbtGreen +
                           .189 * pixel.rgbtBlue);
      int sepiaGreen = round(.349 * pixel.rgbtRed + .686 * pixel.rgbtGreen +
                             .168 * pixel.rgbtBlue);
      int sepiaBlue = round(.272 * pixel.rgbtRed + .534 * pixel.rgbtGreen +
                            .131 * pixel.rgbtBlue);
      image[i][j].rgbtRed = sepiaRed > 255 ? 255 : sepiaRed;
      image[i][j].rgbtGreen = sepiaGreen > 255 ? 255 : sepiaGreen;
      image[i][j].rgbtBlue = sepiaBlue > 255 ? 255 : sepiaBlue;
    }
  }
  return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width]) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width / 2; j++) {
      RGBTRIPLE temp = image[i][j];
      image[i][j] = image[i][width - j - 1];
      image[i][width - j - 1] = temp;
    }
  }
  return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width]) {
  RGBTRIPLE copy[height][width];
  int dx[] = {-1, 0, 1};
  int dy[] = {-1, 0, 1};
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      copy[i][j] = image[i][j];
    }
  }
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      int red = 0;
      int green = 0;
      int blue = 0;
      int count = 0;
      for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
          int ni = i + dx[k];
          int nj = j + dy[l];
          if (ni >= 0 && ni < height && nj >= 0 && nj < width) {
            red += copy[ni][nj].rgbtRed;
            green += copy[ni][nj].rgbtGreen;
            blue += copy[ni][nj].rgbtBlue;
            count++;
          }
        }
      }
      image[i][j].rgbtRed = round((float)red / count);
      image[i][j].rgbtGreen = round((float)green / count);
      image[i][j].rgbtBlue = round((float)blue / count);
    }
  }
  return;
}
