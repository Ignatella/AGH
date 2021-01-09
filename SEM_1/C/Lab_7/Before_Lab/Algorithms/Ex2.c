void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap_array(int size, int array[size]) {
    int *i = array;
    int *j = array + size - 1;
    for (; j - i >= 1; ++i, --j) {
        swap(i, j);
    }
}

int main() {
    int array[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    swap_array(11, array);

    return 0;
}
