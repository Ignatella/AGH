#include <stdio.h>
#include <stdlib.h>
#include "math.h"

#define I 100
#define EPS 1E-8
#define N 1

double zad1a_f1(double x) { return 2 * x * x + 45. / 4 * pow(x, 6) - 2; } // f(x) = 0
double zad1a_f2(double x) { return 3. / 2 * pow(x, 3); }                 // y(x)

double zad1a_df1(double x) { return 67.5 * pow(x, 5) + 4 * x; } // df(x) = 0

double zad1b_f1(double x) { return cos(2 * pow(x, 3)) - 96 * pow(log(1 + x * x), 5) + 1; } // f(x)=  0
double zad1b_f2(double x) { return 2 * log(1 + x * x); }                                   // y(x)

double zad1b_df1(double x) { return -(960 * x * pow(log(1 + x * x), 4)) / (1 + x * x) - 6 * x * x * sin(2 * pow(x, 3)); } // df(x) = 0

double bisekcja(double f(double x), double a, double b, size_t *iterations);
double newton(double f(double), double df(double), double x, size_t *iterations);

int main()
{
    size_t iterations;

    // Zadanie 1a, bisekcja
    {
        double x = bisekcja(zad1a_f1, 0, 20, &iterations);
        double y = zad1a_f2(x);
        printf("Zadanie 1a [Bisekcja], x = %.3f, y = %.3f, iterations = %ld\n", x, y, iterations);
    }

    // Zadanie 1a, newton
    {
        double x = newton(zad1a_f1, zad1a_df1, 20, &iterations);
        double y = zad1a_f2(x);
        printf("Zadanie 1a [Newton],   x = %.3f, y = %.3f, iterations = %ld\n", x, y, iterations);
    }

    printf("\n");

    // Zadanie 1b, bisekcja
    {
        double x = bisekcja(zad1b_f1, 0, 20, &iterations);
        double y = zad1b_f2(x);
        printf("Zadanie 1b [Bisekcja], x = %.3f, y = %.3f, iterations = %ld\n", x, y, iterations);
    }

    // Zadanie 1b, newton
    {
        double x = newton(zad1b_f1, zad1b_df1, 1, &iterations);
        double y = zad1b_f2(x);
        printf("Zadanie 1b [Newton],   x = %.3f, y = %.3f, iterations = %ld\n", x, y, iterations);
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

        if (fabs(f(x)) < EPS)
            break;
    }

    *iterations = i;

    return x;
}
