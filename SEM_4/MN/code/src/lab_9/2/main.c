#include <stdio.h>
#include <stdlib.h>
#include "math.h"

#define I 10000
#define EPS 1E-5

double zad2a_f1(size_t N, double x[N]) { return 0.5 * sin(0.5 * x[0] + x[1]); }
double zad2a_f2(size_t N, double x[N]) { return 0.5 * cos(x[0] - 0.5 * x[1]); }

double zad2b_f1(size_t N, double x[N]) { return -x[0] / (1 + pow(x[0], 2)) + 1 / 3. * sin(x[1]); }
double zad2b_f2(size_t N, double x[N]) { return 0.2 * cos(x[0]) + 0.5 * x[1] / (3 + pow(x[1], 2)); }

size_t fixedPointSimpleIter(size_t N, double (*f[N])(size_t N, double x[N]), double x[N], unsigned int k);
void printSolution(const char *name, size_t N, double (*f[N])(size_t N, double x[N]), double x[N], size_t iterations);

int main(void)
{
    // Zadanie 2a
    {
        size_t N = 2;

        double (**funcs)(size_t N, double x[N]) = alloca(sizeof(void *) * N);
        double *x = alloca(sizeof(double) * N);

        funcs[0] = zad2a_f1, funcs[1] = zad2a_f2;
        x[0] = 0, x[1] = 0;

        size_t iterations = fixedPointSimpleIter(N, funcs, x, I);
        printSolution("Zadanie 2a", N, funcs, x, iterations);
    }

    // Zadanie 2b
    {
        size_t N = 2;

        double (**funcs)(size_t N, double x[N]) = alloca(sizeof(void *) * N);
        double *x = alloca(sizeof(double) * N);

        funcs[0] = zad2b_f1, funcs[1] = zad2b_f2;
        x[0] = 0, x[1] = 0;

        size_t iterations = fixedPointSimpleIter(N, funcs, x, I);
        printSolution("Zadanie 2b", N, funcs, x, iterations);
    }

    return 0;
}

size_t fixedPointSimpleIter(size_t N, double (*f[N])(size_t N, double x[N]), double x[N], unsigned int k)
{
    double x1[N];

    for (size_t i = 0; i < k; i++)
    {
        for (size_t j = 0; j < N; j++)
            x1[j] = (*f[j])(N, x);

        for (size_t j = 0; j < N; j++)
            x[j] = x1[j];

        int accurate = 1;
        for (size_t j = 0; j < N; j++)
        {
            accurate = accurate && (fabs(x1[j] - (*f[j])(N, x1)) < EPS);
        }

        if (accurate)
        {
            return i;
        }
    }
}

void printSolution(const char *name, size_t N, double (*f[N])(size_t N, double x[N]), double x[N], size_t iterations)
{
    printf("%s:\n", name);
    printf("Took %ld iterations\n", iterations);
    printf("x = (");

    for (size_t i = 0; i < N; i++)
    {
        printf("%.3f, ", x[i]);
    }

    printf("\b\b)\n");

    printf("f(x) = (");

    for (size_t i = 0; i < N; i++)
        printf("%.3f, ", (*f[i])(N, x));

    printf("\b\b)\n\n");
}
