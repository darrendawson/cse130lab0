/*
  Darren Dawson
  dwdawson@ucsc.edu
  CSE 130, Lab 0: dog
*/

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>


// this function takes an opened file pointer
// it then loads sections of the file into a buffer and prints them
void print_file(int fd, char *filename) {
  ssize_t bytes_read = 1;
  while (bytes_read > 0) {
    uint8_t *buffer[64]; // this buffer can be any size; we choose 64 here
    bytes_read = read(fd, buffer, sizeof(buffer));
    ssize_t bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
    if (bytes_written != bytes_read) {
      fprintf(stderr, "\ndog: %s: error encountered while writing to stdout\n", filename);
      return;
    }
  }
}

// main
int main(int argc, char **argv) {

  // loop over the filenames passed into dog in order to print them
  for (int i = 1; i < argc; i++) {

    int fd = open(argv[i], O_RDONLY);
    if (fd >= 0) {
      print_file(fd, argv[i]);
      close(fd);
    } else {
      fprintf(stderr, "dog: %s: No such file or directory\n", argv[i]);
    }
  }

  fprintf(stdout, "\n");
  return 0;
}
