/*
  Darren Dawson
  dwdawson@ucsc.edu
  CSE 130, Lab 0: dog
*/

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>


// this function takes an opened file pointer
// it then loads sections of the file into a buffer and prints them
void print_file(int fd) {
  int bytes_read = 1;
  while (bytes_read > 0) {
    char *buffer[64];
    bytes_read = read(fd, buffer, sizeof(buffer));
    write(STDOUT_FILENO, buffer, bytes_read);
  }
}

// main
int main(int argc, char **argv) {

  // loop over the filenames passed into dog in order to print them
  for (int i = 1; i < argc; i++) {

    int fd = open(argv[i], O_RDONLY);
    if (fd >= 0) {
      print_file(fd);
      close(fd);
    } else {
      fprintf(stderr, "dog: %s: No such file or directory\n", argv[i]);
    }
  }

  fprintf(stdout, "\n");
  return 0;
}
