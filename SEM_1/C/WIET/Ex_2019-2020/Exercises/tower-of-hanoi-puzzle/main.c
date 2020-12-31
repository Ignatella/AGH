#include <stdio.h>

void fill_array(int size, int array[size]) {
    int max_val = size;
    for (int i = 0; i < size; ++i) {
        if (max_val == 0) {
            return;
        }
        array[i] = max_val--;
    }
}

void fill_array_with_zeroes(int size, int array[size]) {
    for (int i = 0; i < size; ++i) {
        *(array + i) = 0;
    }
}

void print_array(int size, int array[size]) {
    for (int i = size - 1; i > -1; --i) {
        printf("%d\n", array[i]);
    }

    printf("=========\n");
}

int pop(int size, int source[size]) {
    for (int i = size - 1; i > -1; --i) {
        if (*(source + i) != 0) {
            int result = *(source + i);
            *(source + i) = 0;
            return result;
        }
    }

    return 0;
}

void push(int value, int size, int source[size]) {
    for (int i = size - 1; i > -1; --i) {
        if (i == 0 || *(source + i - 1) != 0) {
            *(source + i) = value;
            return;
        }
    }
}

void move(int count, int size, int source[size], int target[size], int buffer[size]) {
    if (count > 0) {
        move(count - 1, size, source, buffer, target);

        int element = pop(size, source);
        push(element, size, target);

        move(count - 1, size, buffer, target, source);
    }
}


int main() {
    printf("Hello, World!\n");
    int size = 8;
    int A[size];
    int B[size];
    int C[size];
    fill_array(size, A);
    fill_array_with_zeroes(size, B);
    fill_array_with_zeroes(size, C);

    print_array(size, A);

    move(size, size, A, C, B);

    print_array(size, C);
    return 0;
}
