#include <stdio.h>
#include <errno.h>


int invalid();


int main()
{

  if (invalid())
    perror("invalid");
  else
    perror("invalid");

  return 0;
}


int invalid()
{
  errno = E2BIG;
}
