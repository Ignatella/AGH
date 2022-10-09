#include <stdio.h>
#include "math.h"
#include <gsl/gsl_math.h>
#include <gsl/gsl_eigen.h>
#include "gsl_helpers.h"
#include "matrix_helpers.h"

#define I 100
#define h 1E-5

double zad1a_f1(size_t N, double x[N]) { return 2 * x[0] * x[0] + 5 * x[1] * x[1] - 2; }
double zad1a_f2(size_t N, double x[N]) { return -3 * pow(x[0], 3) + 2 * x[1]; }

double zad1b_f1(size_t N, double x[N]) { return cos(2 * pow(x[0], 3)) - 3 * pow(x[1], 5) + 1; }
double zad1b_f2(size_t N, double x[N]) { return 2 * log(1 + x[0] * x[0]) - x[1]; }

double zad2a_f1(size_t N, double x[N]) { return 2 * x[0] - sin(0.5 * x[0] + x[1]); }
double zad2a_f2(size_t N, double x[N]) { return x[1] - 0.5 * cos(x[0] - 0.5 * x[1]); }

double zad2b_f1(size_t N, double x[N]) { return x[0] + x[0] / (1 + pow(x[0], 2)) - 1 / 3. * sin(x[1]); }
double zad2b_f2(size_t N, double x[N]) { return 0.4 * cos(x[0]) + x[1] / (3 + pow(x[1], 2)) - 2 * x[1]; }

double zad3a_f1(size_t N, double x[N]) { return 2 * x[0] * x[0] + 3 * x[1] * x[1] - 5; }
double zad3a_f2(size_t N, double x[N]) { return pow(x[0], 3) - log(x[1]); }

double zad3b_f1(size_t N, double x[N]) { return 8 * pow(x[0], 3) + pow(x[1], 3) - 12 * x[0] * x[1]; }
double zad3b_f2(size_t N, double x[N]) { return cos(2 * x[0]) - x[1] * x[1] + 1; }

double zad3c_f1(size_t N, double x[N]) { return 1. / 5. * pow(x[0] - 1, 2) + x[1] * x[1] + 1. / 3. * x[2] * x[2] - 6; }
double zad3c_f2(size_t N, double x[N]) { return x[0] * x[0] - 2.4 * x[0] + 2 * x[1] * x[1] - x[2] + 0.06; }
double zad3c_f3(size_t N, double x[N]) { return cbrt(x[2]) + 21 * sqrt(x[0]) + 20 * sqrt(x[1]) - 25; }

double dfxi(size_t N, double f(size_t N, double x[N]), double x[N], unsigned int i);
gsl_matrix *Df(size_t N, double (*fs[N])(size_t N, double x[N]), double x[N]);
gsl_vector *LUSolve(size_t N, gsl_matrix *A, gsl_vector *b);
gsl_vector *newton(size_t N, double (*fs[N])(size_t N, double x[N]), double x[N]);

void print_solution(const char *name, size_t N, double (*fs[N])(size_t N, double x[N]), double x0[N], double solution[N]);

int main(void)
{
    // Zad 1a
    {
        size_t N = 2;

        double (**fs)(size_t N, double x[N]) = alloca(sizeof(void *) * N);
        double *x0 = alloca(sizeof(double) * N);

        fs[0] = zad1a_f1, fs[1] = zad1a_f2;
        x0[0] = 0.5, x0[1] = 5;

        gsl_vector *solution = newton(N, fs, x0);

        print_solution("Zadanie 1a", N, fs, x0, solution->data);

        gsl_vector_free(solution);
    }

    // Zad 1b
    {
        size_t N = 2;

        double (**fs)(size_t N, double x[N]) = alloca(sizeof(void *) * N);
        double *x0 = alloca(sizeof(double) * N);

        fs[0] = zad1b_f1, fs[1] = zad1b_f2;
        x0[0] = 0.5, x0[1] = 5;

        gsl_vector *solution = newton(N, fs, x0);

        print_solution("Zadanie 1b", N, fs, x0, solution->data);

        gsl_vector_free(solution);
    }

    // Zad 2a
    {
        size_t N = 2;

        double (**fs)(size_t N, double x[N]) = alloca(sizeof(void *) * N);
        double *x0 = alloca(sizeof(double) * N);

        fs[0] = zad2a_f1, fs[1] = zad2a_f2;
        x0[0] = 0.5, x0[1] = 5;

        gsl_vector *solution = newton(N, fs, x0);

        print_solution("Zadanie 2a", N, fs, x0, solution->data);

        gsl_vector_free(solution);
    }

    // Zad 2b
    {
        size_t N = 2;

        double (**fs)(size_t N, double x[N]) = alloca(sizeof(void *) * N);
        double *x0 = alloca(sizeof(double) * N);

        fs[0] = zad2b_f1, fs[1] = zad2b_f2;
        x0[0] = 0.5, x0[1] = 5;

        gsl_vector *solution = newton(N, fs, x0);

        print_solution("Zadanie 2b", N, fs, x0, solution->data);

        gsl_vector_free(solution);
    }

    // Zad 3a
    {
        size_t N = 2;

        double (**fs)(size_t N, double x[N]) = alloca(sizeof(void *) * N);
        double *x0 = alloca(sizeof(double) * N);

        fs[0] = zad3a_f1, fs[1] = zad3a_f2;
        x0[0] = 0.5, x0[1] = 5;

        gsl_vector *solution = newton(N, fs, x0);

        print_solution("Zadanie 3a", N, fs, x0, solution->data);

        gsl_vector_free(solution);
    }

    // Zad 3b
    {
        size_t N = 2;

        double (**fs)(size_t N, double x[N]) = alloca(sizeof(void *) * N);
        double *x0 = alloca(sizeof(double) * N);

        fs[0] = zad3b_f1, fs[1] = zad3b_f2;
        x0[0] = 0.5, x0[1] = 5;

        gsl_vector *solution = newton(N, fs, x0);

        print_solution("Zadanie 3b", N, fs, x0, solution->data);

        gsl_vector_free(solution);
    }

    // Zad 3c
    {
        size_t N = 3;

        double (**fs)(size_t N, double x[N]) = alloca(sizeof(void *) * N);
        double *x0 = alloca(sizeof(double) * N);

        fs[0] = zad3c_f1, fs[1] = zad3c_f2, fs[2] = zad3c_f3;
        x0[0] = 0.0001, x0[1] = 1.1, x0[2] = 4;

        gsl_vector *solution = newton(N, fs, x0);

        print_solution("Zadanie 3c", N, fs, x0, solution->data);

        gsl_vector_free(solution);
    }

    return 0;
}

double dfxi(size_t N, double f(size_t N, double x[N]), double x[N], unsigned int i)
{
    double *xu = alloca(sizeof(double) * N);
    double *xl = alloca(sizeof(double) * N);

    for (size_t j = 0; j < N; j++)
    {
        xl[j] = x[j];
        xu[j] = x[j];

        if (j == i)
        {
            xl[j] -= h;
            xu[j] += h;
        }
    }

    return (f(N, xu) - f(N, xl)) / 2 / h;
}

gsl_matrix *Df(size_t N, double (*fs[N])(size_t N, double x[N]), double x[N])
{
    gsl_matrix *D = gsl_matrix_calloc(N, N);

    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            m_set(D, i, j, dfxi(N, fs[i], x, j));
        }
    }

    return D;
}

gsl_vector *LUSolve(size_t N, gsl_matrix *A, gsl_vector *b)
{
    gsl_vector *x = gsl_vector_calloc(N);
    gsl_permutation *p = gsl_permutation_calloc(N);
    int sign = 0;

    gsl_linalg_LU_decomp(A, p, &sign);
    gsl_linalg_LU_solve(A, p, b, x);

    gsl_permutation_free(p);

    return x;
}

gsl_vector *newton(size_t N, double (*fs[N])(size_t N, double x[N]), double x[N])
{
    gsl_vector *solution = gsl_vector_calloc(N);

    for (size_t i = 0; i < N; i++)
    {
        v_set(solution, i, x[i]);
    }

    for (size_t i = 0; i < I; i++)
    {
        gsl_vector *b = gsl_vector_calloc(N);
        for (size_t j = 0; j < N; j++)
        {
            v_set(b, j, -fs[j](N, solution->data));
        }

        gsl_matrix *A = Df(N, fs, solution->data);

        gsl_vector *s = LUSolve(N, A, b);

        gsl_vector_add(solution, s);

        gsl_vector_free(b);
        gsl_matrix_free(A);
        gsl_vector_free(s);
    }

    return solution;
}

void print_solution(const char *name, size_t N, double (*fs[N])(size_t N, double x[N]), double x0[N], double solution[N])
{
    printf("%s:\n", name);

    printf("Punkt startowy (");
    for (size_t i = 0; i < N; i++)
    {
        printf("%.3f, ", x0[i]);
    }

    printf("\b\b)\n");
    printf("x = (");

    for (size_t i = 0; i < N; i++)
    {
        printf("%.3f, ", solution[i]);
    }

    printf("\b\b)\n");
    printf("f(x) = (");

    for (size_t i = 0; i < N; i++)
    {
        printf("%.3f, ", fs[i](N, solution));
    }

    printf("\b\b)\n\n\n");
}
