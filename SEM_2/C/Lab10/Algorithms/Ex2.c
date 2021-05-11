#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef double matFunc(double x);

typedef matFunc *matFuncArr[];
typedef char *stringArr[];


typedef struct matFuncRes {
    int *funcIndexes;
    size_t funcsSize;
    double resultValue;
    double arg;
} matFuncRes;

double f0Log(double x) {
    return log(x);
}

double f1Square(double x) {
    return pow(x, 2);
}

double f2Exp(double x) {
    return exp(x);
}

double f3Sin(double x) {
    return sin(x);
}

matFuncRes *matFuncMax(double arg, size_t size, matFuncArr arr) {
    int *funcIndexes = NULL;

    size_t s = 0;
    size_t cap = 0;

    double max = arr[0](arg);
    for (int i = 0; i < size; ++i) {
        double cur = arr[i](arg);
        if (cur < max)
            continue;

        if (cur > max) {
            max = cur;
            s = 0;
        }

        if (s == cap) {
            cap = cap == 0 ? 1 : cap * 2;
            funcIndexes = realloc(funcIndexes, cap * sizeof(int));
        }

        funcIndexes[s++] = i;
    }

    funcIndexes = realloc(funcIndexes, s * sizeof(int));

    matFuncRes *result = calloc(1, sizeof(matFuncRes));
    result->funcIndexes = funcIndexes;
    result->funcsSize = s;
    result->resultValue = max;
    result->arg = arg;
    return result;
}

void printFuncs(matFuncRes *res, stringArr names, struct _IO_FILE *stream) {
    for (int i = 0; i < res->funcsSize; ++i) {
        fprintf(stream, "For arg = %f the biggest value = %f returns function %s\n",
                res->arg, res->resultValue, names[res->funcIndexes[i]]);
    }

    fprintf(stream, "\n\n");
}

int main() {
    size_t size = 4;

    matFuncArr arr = {f0Log, f1Square, f2Exp, f3Sin};
    stringArr names = {"Log", "Square", "Exp", "Sin"};

    int argCount = 10;
    double args[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int i = 0; i < argCount; ++i) {
        matFuncRes *res = matFuncMax(args[i], size, arr);
        printFuncs(res, names, stdout);

        free(res->funcIndexes);
        free(res);
    }

    printf("End of program!\n");
    return 0;
}
