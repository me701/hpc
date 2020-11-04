#ifndef TIMER_HH_
#define TIMER_HH_

#include <sys/time.h>
#include <cstddef>

double time()
{
  struct timeval t;
  gettimeofday(&t, NULL);
  return (double)(t.tv_sec + t.tv_usec/1000000.0);
}


#endif // TIMER_HH__