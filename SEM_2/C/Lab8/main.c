#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef void (*someFnc)(int a);

struct comb {
    double re;
    double im;
} s1 = {5.0, 3.0};

typedef struct com_mod {
    struct comb ze;
    double mod;
    someFnc fnc1;

    void (*fnc2)(struct com_mod *structure);
} com_mod;

void f(struct com_mod *device) {
    printf("|%f+%f*i|=%f\n", device->ze.re, device->ze.im, device->mod);
}

void c(int k) {
};

int main() {
    int count = 10;
    struct com_mod tab[count];

    for (int i = 0; i < count; i++) {
        tab[i].ze.re = 5;
        tab[i].ze.im = 5;
        tab[i].fnc1 = c;
        tab[i].fnc2 = f;
        tab[i].fnc2(tab + i); // print
        tab[i].fnc1(19);
    }
}
