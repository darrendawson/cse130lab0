/*
  Darren Dawson
  dwdawson@ucsc.edu
  CSE 130, Lab 0: dog
*/

#include <stdio.h>

int main(int argc, char **argv) {

  // loop over the filenames passed into dog in order to print them
  for (int i = 1; i < argc; i++) {
    printf(argv[i]);
  }

  return 0;
}
