#include "greaterclass.h"

/**
 * @brief Zwraca max of type T
 * 
 * @tparam T 
 * @param t1 
 * @param t2 
 * @return T 
 */
template <class T>
T Tmax(const T &t1, const T &t2) { return t1 > t2 ? t1 : t2; }

/**
 * @brief Zwraca max z tablicy elementow of type T
 * 
 * @tparam T 
 * @param arr 
 * @param size 
 * @return T 
 */
template <class T>
T Tmax(T *arr, unsigned int size)
{
    if (arr == nullptr || size == 0)
        exit(EXIT_FAILURE);

    if (size > 1)
        return Tmax(arr[size - 1], Tmax(arr, size - 1));

    return arr[0];
}

/**
 * @brief Zamienia T miejscami
 * 
 * @tparam T 
 * @param t1 
 * @param t2 
 */
template <class T>
void Tswap(T &t1, T &t2)
{
    T temp(t1);
    t1 = t2;
    t2 = temp;
};

/**
 * @brief Konwertuje K na T
 * 
 * @tparam T 
 * @tparam K 
 * @param v 
 * @return T 
 */
template <class T, class K>
T convert(K v)
{
    return static_cast<T>(v);
};
