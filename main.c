#include "stdio.h"
# include <pthread.h>
# include <sys/time.h>
# include <fcntl.h>

int main()
{
   struct timeval time;
   size_t time_usec;
   size_t time_sec;

   gettimeofday(&time , NULL);
   time_usec = time.tv_usec;
   time_sec = time.tv_sec;
   printf("time now in second : %lu\n", time_sec);
   printf("time now in microsecond : %zu\n", time_usec);
}