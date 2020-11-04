#ifndef TRIAD_HH_
#define TRIAD_HH_


class Triad
{

public:

Triad(const int N);
~Triad();
void run();

private:

inline void dummy(double *a, double *b, double *c, double *d);

const int _N;
double* _A;
double* _B;
double* _C;
double* _D;

};


#endif // TRIAD_HH_