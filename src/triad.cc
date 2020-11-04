#include "triad.hh"
#include "timer.hh"

#include <cstdio>
#include <cmath>
#include <vector>

Triad::Triad(const int N)
  : _N(N)
{
    _A = new double[_N];
    _B = new double[_N];
    _C = new double[_N];
    _D = new double[_N];

    for (int i = 0; i < _N; ++i)
    {
        _A[i] = 0.0;
        _B[i] = 1.0;
        _C[i] = 2.0;
        _D[i] = 3.0;
    }
}

Triad::~Triad()
{
    delete [] _A;
    delete [] _B;
    delete [] _C;
    delete [] _D;
}

void Triad::run()
{
    for (int i = 0; i < _N; ++i)
    {
        _A[i] = _B[i] + _C[i]*_D[i];
    }
    if (_A[_N] < 0.0) dummy(_A, _B, _C, _D);
}

void Triad::dummy(double *a, double *b, double *c, double *d)
{
  std::printf("I should never be called!!!!! %10.4f", a[0]);
}

// 10^a to 10^b
void logspace(std::vector<int>& v, int a, int b, int n)
{
  double logx = a;
  double dlogx = (b-a)/(double)n; 
  for (int i = 0; i < n; ++i)
  {
    v.push_back(std::pow(10, logx));
    logx += dlogx;
  }
}

int main()
{
  const double max_time = 0.125; // seconds
  FILE* fh = fopen ("triad.txt","w");
  std::vector<int> nvals;
  logspace(nvals, 3, 7, 100);
  for (int i = 0; i < nvals.size(); ++i)
  {
    int n = nvals[i];
    Triad triad(n);
    double te = 0.0;
    int c = 0;
    while (te < max_time)
    {
      double t0 = time();
      triad.run();
      te += time() - t0;
      c += 1;
    }
    double gflops = (double)n*(double)c*2.0/1.0e9/te;
    std::printf("%8i %6.2e %6.2e\n", n, (double)c, gflops);
    std::fprintf(fh, "%8i %6.2e %6.2e\n", n, (double)c, gflops);
  }
  std::fclose(fh);
  return 0;
}