#include "greaterclass.h"
#include <utility>

const Greater &max(const Greater &a, const Greater &b)
{
    return (a > b) ? a : b;
}

Greater &max(Greater *arr, unsigned int size)
{
    if (arr == nullptr || size == 0)
        exit(EXIT_FAILURE);

    Greater &g = arr[0];

    for (size_t i = 1; i < size; i++)
    {
        g = max(g, arr[i]);
    }

    return g;
}

void swap(Greater &g1, Greater &g2)
{
    // Greater &tmp = g1.clone();

    // Greater &tmp = g1;
    g1 = g2;
    // g2 = tmp;
}