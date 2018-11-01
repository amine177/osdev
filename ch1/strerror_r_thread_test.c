#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>


pthread_mutex_t v;


void print_error(int i)
{
  char buf[30];
  pthread_mutex_lock(&v);
  strerror_r(i, buf, 30);
  pthread_mutex_unlock(&v);
  printf("buf: %s\n", buf);
}

int main()
{
  int s1, s2;
  pthread_t t1, t2;

  s1 = pthread_create(&t1, NULL, (void *)print_error, (void *)1);
  s2 = pthread_create(&t2, NULL, (void *)print_error, (void *)3);

  if (s1)
    perror("main");
  if (s2)
    perror("main");

  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  return 0;
}
