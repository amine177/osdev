#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[])
{
  int errno;

  if (argc != 2) {
    printf("Usage: strerror_test.o errno\n");
    exit(1);
  }

  errno = (int) atoi(*++argv);
  printf("strerror(%d): %s\n", errno, strerror(errno));

  return 0;
}
