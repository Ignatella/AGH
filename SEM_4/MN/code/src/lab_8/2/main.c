#include "stdio.h"
#include "math.h"

#define I 100

double f(double a, double n, double x) { return pow(x, n) - a; }
double df(double n, double x) { return n * pow(x, n - 1); }

double nRoot(double x, double n, double a);

int main()
{
    double a = 225;
    double n = 2;
    double x = a;

    double res = nRoot(a, n, x);
    printf("x = %.3f\n", res);

    return 0;
}

double nRoot(double a, double n, double x)
{
    for (size_t i = 0; i < I; i++)
    {
        x = x - f(a, n, x) / df(n, x);
    }

    return x;
}
