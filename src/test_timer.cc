#include "timer.hh"

#include <cmath>
#include <cstdio>

int main(){
  const int n = 1000000;
  const double delta = 1.0/(double)n;
  double s = 0;

  double t0 = time();

  for (int i = 0; i < n; ++i)
  {
    s += std::cos(i*delta) * delta;
  }

  double te = time()-t0;
  std::printf("       sin(1) ~= %10.6e\n", s);
  std::printf(" elapsed time =  %10.6e seconds\n", te);
}