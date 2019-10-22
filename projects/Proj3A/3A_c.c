#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pixel{
  unsigned char r;
  unsigned char g;
  unsigned char b;
} Pixel;

typedef struct Image{
  char magicnumber[128];
  int width;
  int height;
  int maxval;
  Pixel *pixel;
} Image;

Image *ReadImage(char *filename)
{
  FILE *f_in;
  int buffer_size;
  int *buffer;
  Image *image;

  image = (Image *) malloc(sizeof(Image));

  f_in = fopen(filename, "rb");

  fscanf(f_in, "%s\n%d %d\n%d\n", image->magicnumber, &(image->width), &(image->height), &(image->maxval));

  image->pixel = (Pixel *) malloc(sizeof(Pixel) * image->width * image->height);

  for(int i = 0; i < image->height; i++){
    for(int j = 0; j < image->width; j++){
      fread(&(image->pixel[i * image->width + j].r), 1, 1, f_in);
      fread(&(image->pixel[i * image->width + j].g), 1, 1, f_in);
      fread(&(image->pixel[i * image->width + j].b), 1, 1, f_in);
    }
  }

  fclose(f_in);

  return image;
}


void WriteImage(Image *image, char *filename)
{
  FILE *f_out;

  f_out = fopen(filename, "wb");

  //Writing header out to file.
  fprintf(f_out, "%s\n%d %d\n%d\n", image->magicnumber, image->width, image->height, image->maxval);

  //Writing out pixel data
  for(int i = 0; i < image->height; i++){
    for(int j = 0; j < image->width; j++){
      fwrite(&(image->pixel[i * image->width + j].r), 1, 1, f_out);
      fwrite(&(image->pixel[i * image->width + j].g), 1, 1, f_out);
      fwrite(&(image->pixel[i * image->width + j].b), 1, 1, f_out);
    }
  }
  fclose(f_out);
}


Image *CopyImage(Image *input)
{
  Image *copy;

  copy = (Image *) malloc(sizeof(Image));
  copy->pixel = (Pixel *) malloc(sizeof(Pixel) * input->width * input->height);

  strcpy(copy->magicnumber, input->magicnumber);
  copy->width = input->width;
  copy->height = input->height;
  copy->maxval = input->maxval;
  for(int i = 0; i < copy->height; i++){
    for(int j = 0; j < copy->width; j++){
        copy->pixel[i * copy->width + j].r = input->pixel[i * input->width + j].r;
        copy->pixel[i * copy->width + j].g = input->pixel[i * input->width + j].g;
        copy->pixel[i * copy->width + j].b = input->pixel[i * input->width + j].b;
    }
  }

  return copy;
}


Image *YellowDiagonal(Image *input)
{
  Image *newImage;

  newImage = CopyImage(input);

  for(int i = 0; i < newImage->height; i++){
    for(int j = 0; j < newImage->width; j++){
      if(i == j){
        newImage->pixel[i * newImage->width + j].r = 255;
        newImage->pixel[i * newImage->width + j].g = 255;
        newImage->pixel[i * newImage->width + j].b = 0;
      }
    }
  }

  return newImage;
}


void FreeImage(Image *image){
    free(image->pixel);
    free(image);
}


int main(int argc, char *argv[])
{
  Image *image;
  Image *manipulated;
   /* Read an image, apply yellow diagonal to it, then write */
  image = ReadImage(argv[1]);
  manipulated = YellowDiagonal(image);

  WriteImage(manipulated, argv[2]);

  FreeImage(image);
  FreeImage(manipulated);

  return 1;
}