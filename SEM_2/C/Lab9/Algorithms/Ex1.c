#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdarg.h>

typedef struct complex {
    double real;
    double imaginary;
} complex;

typedef enum operation {
    Add,
    Subtract,
    Multiply,
    Divide
} operation;

void printComplex(complex *num) {
    printf("Real: %lf, Imaginary: %lf\n", num->real, num->imaginary);
}

complex *calculator(complex *f, complex *s, operation operation) {
    complex *result = calloc(1, sizeof(complex));
    if (operation == Add) {
        result->real = f->real + s->real;
        result->imaginary = f->imaginary + s->imaginary;
    }

    if (operation == Subtract) {
        result->real = f->real - s->real;
        result->imaginary = f->imaginary - s->imaginary;
    }

    if (operation == Multiply) {
        result->real = f->real * s->real - f->imaginary * s->imaginary;
        result->imaginary = f->real * s->imaginary + s->real * f->imaginary;
    }

    if (operation == Divide) {
        result->real = (f->real * s->real + f->imaginary * s->imaginary)
                       / (pow(s->real, 2) + pow(s->imaginary, 2));

        result->imaginary = (f->imaginary * s->real - f->real * s->imaginary)
                            / (pow(s->real, 2) + pow(s->imaginary, 2));
    }

    return result;
}

void freeMem(int pointerCount, ...) {
    va_list params;
    va_start(params, pointerCount);
    for (int i = 0; i < pointerCount; ++i) {
        void *ptr = va_arg(params, void *);
        free(ptr);
        ptr = NULL;
    }
    va_end(params);
}

int main() {
    double a, b, c, d;
    printf("Please, provide real part of first number:\n");
    scanf("%lf", &a);

    printf("Please, provide imaginary part of first number:\n");
    scanf("%lf", &b);

    printf("Please, provide real part of second number:\n");
    scanf("%lf", &c);

    printf("Please, provide imaginary part of second number:\n");
    scanf("%lf", &d);

    complex num1 = {.real = a, .imaginary = b};
    complex num2 = {.real = c, .imaginary = d};
    printf("There are two complex numbers:\n");
    printComplex(&num1);
    printComplex(&num2);

    complex *addRes = calculator(&num1, &num2, Add);
    complex *subRes = calculator(&num1, &num2, Subtract);
    complex *mulRes = calculator(&num1, &num2, Multiply);
    complex *divRes = calculator(&num1, &num2, Divide);

    printf("Add result:\n");
    printComplex(addRes);
    printf("Subtract result:\n");
    printComplex(subRes);
    printf("Multiply result:\n");
    printComplex(mulRes);
    printf("Divide result:\n");
    printComplex(divRes);

    freeMem(4, addRes, subRes, mulRes, divRes);

    printf("End of program.\n");
    return 0;
}
