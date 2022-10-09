#include "stdio.h"
#include "math.h"

#define I 100
#define EPS 1E-8

double f1(double x) { return 5 * pow(x, 3) + log(x) + tan(x) + 1.65; }
double f2(double x) { return (x * x) * cos(x); }

double df1(double x) { return 15 * pow(x, 2) + 1 / x + 1 + pow(tan(x), 2); }
double df2(double x) { return x * (2 * cos(x) - x * sin(x)); }

double bisekcja(double f(double x), double a, double b, size_t *iterations);
double newton(double f(double), double df(double), double x, size_t *iterations);

int main()
{
    size_t iterations;

    // Bisekcja
    {
        printf("Bisekcja: \n");

        double res = bisekcja(f1, 0, 20, &iterations);
        printf("%s, x = %.3f, iterations = %ld\n", "f1", res, iterations);
    }

    printf("\n\n");

    // Newtona
    {
        printf("Newtona: \n");

        double res = newton(f1, df1, 20, &iterations);
        printf("%s, x = %.3f, iterations = %ld\n", "f1", res, iterations);
    }

    printf("\n\n");

    // Bisekcja
    {
        printf("Bisekcja: \n");

        double res = bisekcja(f2, 3, 6, &iterations);
        printf("%s, x = %.3f, iterations = %ld\n", "f2", res, iterations);
    }

    printf("\n\n");

    // Newtona
    {
        printf("Newtona: \n");

        double res = newton(f2, df2, 6, &iterations);
        printf("%s, x = %.3f, iterations = %ld\n", "f2", res, iterations);
    }

    return 0;
}

double bisekcja(double f(double x), double a, double b, size_t *iterations)
{
    double x, y, ya = f(a), yb = f(b);
    size_t i = 0;

    do
    {
        x = (a + b) / 2;
        y = f(x);

        if (y == 0)
            break;

        if (ya * y > 0)
        {
            a = x;
            ya = y;
        }
        else
        {
            b = x;
            yb = y;
        }

        if (i % 5 == 0)
        {
            printf("Iteration: %ld. x: %f\n", i, x);
        }

        i++;
    } while (0.5 * fabs(b - a) > EPS);

    x = (a + b) / 2;

    *iterations = i;

    return x;
}

double newton(double f(double), double df(double), double x, size_t *iterations)
{
    size_t i = 0;

    for (; i < I; i++)
    {
        x = x - f(x) / df(x);

        if (i % 5 == 0)
        {
            printf("Iteration: %ld. x: %f\n", i, x);
        }

        if (fabs(f(x)) < EPS)
            break;
    }

    *iterations = i;

    return x;
}
