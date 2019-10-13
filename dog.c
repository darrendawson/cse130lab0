/*
  Darren Dawson
  dwdawson@ucsc.edu
  CSE 130, Lab 0: dog
*/

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char **argv) {

  // loop over the filenames passed into dog in order to print them
  for (int i = 1; i < argc; i++) {

    int file_pointer = open(argv[i], O_RDONLY);
    if (file_pointer >= 0) {
      printf("" + file_pointer);
      //close(file_pointer);
    } else {
      fprintf(stderr, "dog: %s: No such file or directory\n", argv[i]);
    }
    printf(argv[i]);
    printf("\n");
  }

  return 0;
}
