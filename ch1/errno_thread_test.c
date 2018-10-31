#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>


pthread_mutex_t v;


void errno_change(int i)
{
  pthread_mutex_lock(&v);
  printf("Previous errno: %d\n", errno);
  perror("errno_change");
  errno = i;
  printf("Current errno: %d\n", errno);
  perror("errno_change");
  pthread_mutex_unlock(&v);
}


int main()
{
  pthread_t t1, t2;
  int s1, s2;

  s1 = pthread_create(&t1, NULL, (void *) errno_change,
      (void *) 101);
  s2 = pthread_create(&t2, NULL, (void *) errno_change,
      (void *) 1);

  if (s1 < 0)
    perror("main");
  if (s2 < 0)
    perror("main");

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
  return 0;
}
