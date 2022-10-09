#include <stdio.h>
#include "math.h"
#include "gsl_helpers.h"
#include "linalg_helpers.h"
#include "matrix_helpers.h"
#include "/usr/include/gsl/gsl_errno.h"
#include "/usr/include/gsl/gsl_fft_complex.h"

#define N 128
#define NOISE

double f(double x) { return 5.3 * sin(2 * M_PI * x) - 6.7 * sin(8 * M_PI * x) + 2.1 * sin(14 * M_PI * x); }

double noise() { return (double)rand() / RAND_MAX * 2 - 1; }

int main()
{
    double a = 0, b = 4 * M_PI;

    double dx = (b - a) / N;

    gsl_vector *v = gsl_vector_calloc(2 * N);
    gsl_vector *spec = gsl_vector_calloc(N);

    for (size_t i = 0; i < N; i++)
    {
        double t = dx * i + a;
#ifdef NOISE
        v_set(v, 2 * i, f(t) + noise());
#endif
#ifndef NOISE
        v_set(v, 2 * i, f(t));
#endif

        v_set(v, 2 * i + 1, 0);
    }

    gsl_fft_complex_radix2_forward(v->data, 1, N);

    for (size_t i = 0; i < N; i++)
    {
        double spectrum = pow(v_get(v, 2 * i), 2) + pow(v_get(v, 2 * i + 1), 2);
        printf("Power [%ld]^2 = %.2f\n", i, spectrum);
        v_set(spec, i, spectrum);
    }

    save_vector_to_file("src/lab_11/1/assets/data.txt", spec);

    gsl_vector_free(v);
    gsl_vector_free(spec);

    return 0;
}
