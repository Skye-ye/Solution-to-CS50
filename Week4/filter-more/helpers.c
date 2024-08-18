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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width]) {
  RGBTRIPLE copy[height][width];
  int dx[] = {-1, 0, 1};
  int dy[] = {-1, 0, 1};
  int gx[] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
  int gy[] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      copy[i][j] = image[i][j];
    }
  }
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      int redx = 0;
      int greenx = 0;
      int bluex = 0;
      int redy = 0;
      int greeny = 0;
      int bluey = 0;
      for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
          int ni = i + dx[k];
          int nj = j + dy[l];
          if (ni >= 0 && ni < height && nj >= 0 && nj < width) {
            redx += copy[ni][nj].rgbtRed * gx[k * 3 + l];
            greenx += copy[ni][nj].rgbtGreen * gx[k * 3 + l];
            bluex += copy[ni][nj].rgbtBlue * gx[k * 3 + l];
            redy += copy[ni][nj].rgbtRed * gy[k * 3 + l];
            greeny += copy[ni][nj].rgbtGreen * gy[k * 3 + l];
            bluey += copy[ni][nj].rgbtBlue * gy[k * 3 + l];
          }
        }
      }
      int red = round(sqrt(redx * redx + redy * redy));
      int green = round(sqrt(greenx * greenx + greeny * greeny));
      int blue = round(sqrt(bluex * bluex + bluey * bluey));
      image[i][j].rgbtRed = red > 255 ? 255 : red;
      image[i][j].rgbtGreen = green > 255 ? 255 : green;
      image[i][j].rgbtBlue = blue > 255 ? 255 : blue;
    }
  }
  return;
}
