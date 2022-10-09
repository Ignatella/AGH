#pragma once

#include <stdexcept>
#include <string>
#include <cstring>

namespace obj
{
    /**
     * @brief Bool to text
     *
     * @param val
     * @return std::string
     */
    std::string text(bool val)
    {
        return val ? "TRUE" : "FALSE";
    }

    /**
     * @brief Sprawdza czy liczba jest pierwsza
     *
     * @param n
     * @return true
     * @return false
     */
    bool isPrime(int n)
    {
        if (n == 2 || n == 3)
            return true;

        if (n <= 1 || n % 2 == 0 || n % 3 == 0)
            return false;

        for (int i = 5; i * i <= n; i += 6)
        {
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
        }

        return true;
    }

    /**
     * @brief Zwraca wartosc srednia tablicy
     *
     * @tparam T
     * @param arr
     * @param N
     * @return double
     */
    template <typename T>
    double srednia(const T *arr, unsigned int N)
    {
        double sum = 0;
        for (size_t i = 0; i < N; i++)
        {
            sum += arr[i];
        }

        return sum / N;
    };

    /**
     * @brief Zwraca wartosc srednia tablicy
     *
     * @tparam T
     * @tparam N
     * @return double
     */
    template <typename T, unsigned int N>
    double srednia(const T (&arr)[N])
    {
        return srednia(arr, N);
    };

    /**
     * @brief Zwraca mniejsza wartosc miedzy a i b
     *
     * @tparam T
     * @param a
     * @param b
     * @return T*
     */
    template <typename T>
    T *min(T *a, T *b)
    {
        return *a < *b ? a : b;
    }

    /**
     * @brief Zwraca mniejsza wartosc miedzy a i b
     *
     * @tparam T
     * @param a
     * @param b
     * @return T
     */
    template <typename T>
    T min(T a, T b)
    {
        return *min(&a, &b);
    }

    /**
     * @brief Zwraca wartosc minimalna z tablicy
     *
     * @tparam T
     * @param arr
     * @param N
     * @return T
     */
    template <typename T>
    T min(const T *arr, unsigned int N)
    {
        unsigned int minI = 0;

        for (size_t i = 1; i < N; i++)
        {
            if (arr[i] < arr[minI])
                minI = i;
        }

        return arr[minI];
    }

    /**
     * @brief Zwraca wartosc minimalna z tablicy
     *
     * @tparam T
     * @tparam N
     * @return T
     */
    template <typename T, unsigned int N>
    T min(const T (&arr)[N])
    {
        return min(arr, N);
    }

    /**
     * @brief Zwraca string 'mniejszy' miedzy s1, a s2
     *
     * @tparam
     * @param s1
     * @param s2
     * @return const char*
     */
    template <>
    const char *min(const char *s1, const char *s2)
    {
        return strcmp(s1, s2) < 0 ? s1 : s2;
    }

    /**
     * @brief Zwraca 'minimalny' string z tablicy
     *
     * @param arr
     * @param N
     * @return const char*
     */
    const char *min(const char **arr, unsigned int N)
    {
        unsigned int minI = 0;

        for (size_t i = 1; i < N; i++)
        {
            if (strcmp(arr[i], arr[minI]) < 0)
                minI = i;
        }

        return arr[minI];
    }

    /**
     * @brief Zwraca wartosc maximalna wsrod a i b
     *
     * @tparam T
     * @param a
     * @param b
     * @return T*
     */
    template <typename T>
    T *max(T *a, T *b)
    {
        return *a > *b ? a : b;
    }

    /**
     * @brief Zwraca wartosc maximalna wsrod a i b
     *
     * @tparam T
     * @param a
     * @param b
     * @return T
     */
    template <typename T>
    T max(T a, T b)
    {
        return *max(&a, &b);
    }

    /**
     * @brief Zwraca wartosc maksimalna z tablicy
     *
     * @tparam T
     * @param arr
     * @param N
     * @return T
     */
    template <typename T>
    T max(const T *arr, unsigned int N)
    {
        unsigned int maxI = 0;

        for (size_t i = 1; i < N; i++)
        {
            if (arr[i] > arr[maxI])
                maxI = i;
        }

        return arr[maxI];
    }

    /**
     * @brief Zwraca wartosc maksimalna z tablicy
     *
     * @tparam T
     * @tparam N
     * @return T
     */
    template <typename T, unsigned int N>
    T max(const T (&arr)[N])
    {
        return max(arr, N);
    }

    /**
     * @brief Zwraca 'wiekszy' string wsrod s1, a s2
     *
     * @tparam
     * @param s1
     * @param s2
     * @return const char*
     */
    template <>
    const char *max(const char *s1, const char *s2)
    {
        return strcmp(s1, s2) > 0 ? s1 : s2;
    }

    /**
     * @brief Zwraca wartosc 'maksimalna' z tablicy arr
     *
     * @param arr
     * @param N
     * @return const char*
     */
    const char *max(const char **arr, unsigned int N)
    {
        unsigned int maxI = 0;

        for (size_t i = 1; i < N; i++)
        {
            if (strcmp(arr[i], arr[maxI]) > 0)
                maxI = i;
        }

        return arr[maxI];
    }

    /**
     * @brief Sprawdza, czy elementy (from, to) sa pierwsze
     *
     * @tparam from
     * @tparam to
     * @tparam T
     * @tparam N
     * @return true
     * @return false
     */
    template <unsigned int from, unsigned int to, typename T, unsigned int N>
    bool czyWszystkiePierwsze(const T (&arr)[N])
    {
        bool result = true;

        if (from > to)
            throw std::invalid_argument("From is out of range.");

        if (to < from || to > N)
            throw std::invalid_argument("To is out of range.");

        for (size_t i = from + 1; i < to; i++)
        {
            result = result && isPrime(arr[i]);
        }

        return result;
    }
}
