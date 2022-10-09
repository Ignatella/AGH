#include "stdio.h"
#include "math.h"

#define N 8
#define I 100
#define EPS 0.001

double f_zad1_a(double x) { return pow(x, 3) + 2 * x - 1; }
double f_zad1_b(double x) { return x - 3 * sin(x) - 1; }
double f_zad1_c(double x) { return x * log(x) + sin(x); }
double f_zad1_d(double x) { return exp(-3 * x) + pow(x, 5) - 3 * pow(x, 2) + 1; }

double f_zad2_a(double x) { return pow(x, 5) + 3 * pow(x, 3) + 2; }
double f_zad2_b(double x) { return pow(M_E, x) - pow(x, 2) - 1; }
double f_zad2_c(double x) { return atan(x) - x / (pow(x, 2) + 1); }
double f_zad2_d(double x) { return sin(sin(x)); }

double df_zad1_a(double x) { return 3 * x * x + 2; }
double df_zad1_b(double x) { return 1 - 3 * cos(x); }
double df_zad1_c(double x) { return log(x) + cos(x) + 1; }
double df_zad1_d(double x) { return 5 * pow(x, 4) - 6 * x - 3 * exp(-3 * x); }

double df_zad2_a(double x) { return 5 * pow(x, 4) + 9 * pow(x, 2); }
double df_zad2_b(double x) { return pow(M_E, x) - 2 * x; }
double df_zad2_c(double x) { return 2 * pow(x, 2) / pow((pow(x, 2) + 1), 2); }
double df_zad2_d(double x) { return cos(x) * cos(sin(x)); }

double bisekcja(double f(double x), double a, double b, size_t *iterations);
double newton(double f(double), double df(double), double x, size_t *iterations);
double falsi(double f(double x), double a, double b, size_t *iterations);

int main()
{
    double (*funcs[N])(double x) = {f_zad1_a, f_zad1_b, f_zad1_c, f_zad1_d, f_zad2_a, f_zad2_b, f_zad2_c, f_zad2_d};
    double (*dfuncs[N])(double x) = {df_zad1_a, df_zad1_b, df_zad1_c, df_zad1_d, df_zad2_a, df_zad2_b, df_zad2_c, df_zad2_d};
    char *funcNames[N] = {"f_zad1_a", "f_zad1_b", "f_zad1_c", "f_zad1_d", "f_zad2_a", "f_zad2_b", "f_zad2_c", "f_zad2_d"};

    double ab[2 * N] = {-1., 1, 0., 5., 0.1, 1, 0, 1, -1, 0, -1, 1, -1, 1, 1, 5};
    double x0[N] = {1, 3, 1, 1, 1, 1, 1, 3};

    size_t iterations;

    // Bisekcja
    {
        printf("Bisekcja: \n");

        for (size_t i = 0; i < N; i++)
        {
            double res = bisekcja(funcs[i], ab[i * 2], ab[i * 2 + 1], &iterations);
            printf("%s, x = %+.3f, iterations = %ld\n", funcNames[i], res, iterations);
        }
    }

    printf("\n\n");

    // Newtona
    {
        printf("Newtona: \n");

        for (size_t i = 0; i < N; i++)
        {
            double res = newton(funcs[i], dfuncs[i], x0[i], &iterations);
            printf("%s, x = %+.3f, iterations = %ld\n", funcNames[i], res, iterations);
        }
    }

    printf("\n\n");

    // Falsi
    {
        printf("Falsi: \n");

        for (size_t i = 0; i < N; i++)
        {
            double res = falsi(funcs[i], ab[i * 2], ab[i * 2 + 1], &iterations);
            printf("%s, x = %+.3f, iterations = %ld\n", funcNames[i], res, iterations);
        }
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

double falsi(double f(double x), double a, double b, size_t *iterations)
{
    double result;
    size_t i = 0;

    for (; i < I; i++)
    {
        double fa = f(a);
        double fb = f(b);

        double c = result = (a * fb - b * fa) / (fb - fa);

        double fc = f(c);

        if (fabs(fc) < EPS)
            break;

        if (fa * fc < 0)
            b = c;
        else
            a = c;
    }

    *iterations = i;

    return result;
}
