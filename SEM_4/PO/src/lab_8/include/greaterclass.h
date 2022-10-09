#pragma once

#include <iostream>
#include <cstring>

/**
 * @brief Abstrakcja dla porownania
 *
 */
class Greater
{
public:
    /**
     * @brief Operator mniejsze
     *
     * @param g1
     * @return true
     * @return false
     */
    virtual bool operator<(const Greater &g1) const = 0;

    /**
     * @brief Operator wieksze
     *
     * @param g1
     * @param g2
     * @return true
     * @return false
     */
    friend bool operator>(const Greater &g1, const Greater &g2) { return !g1.operator<(g2); };

    virtual Greater &clone() const = 0;
};

/**
 * @brief Wrapper nad int
 *
 */
class Int : public Greater
{
private:
    /**
     * @brief Przechowywana wartosc
     *
     */
    int _v;

public:
    /**
     * @brief Tworzy Int
     *
     */
    Int() : Int(0){};

    /**
     * @brief Tworzy Int
     *
     * @param v
     */
    Int(int v) : _v(v){};

    Greater &clone() const override
    {
        static Int klon(*this);
        return static_cast<Greater &>(klon);
    }

    /**
     * @brief Porownuje Int
     *
     * @param g1
     * @return true
     * @return false
     */
    bool operator<(const Greater &g1) const override
    {
        const Int &i1 = static_cast<const Int &>(g1);
        return _v < i1._v;
    }

    /**
     * @brief Wypisuje Int
     *
     */
    void print() const { operator<<(std::cout, *this); }

    /**
     * @brief Kastuje na Int
     *
     * @return int
     */
    operator int() const { return _v; }

    /**
     * @brief Wypisuje Int
     *
     * @param os
     * @param i
     * @return std::ostream&
     */
    friend std::ostream &operator<<(std::ostream &os, const Int &i)
    {
        os << i._v;
        return os;
    }
};

/**
 * @brief Abstrakcja nad string
 *
 */
class String : public Greater
{
private:
    /**
     * @brief Przechowywana wartosc
     *
     */
    char *_v;

public:
    /**
     * @brief Tworzy String
     *
     * @param v
     */
    String(const char *v)
    {
        unsigned int len = strlen(v);
        _v = new char[len + 1]();
        strcpy(_v, v);
    };

    /**
     * @brief Konstruktor kopiujacy
     *
     * @param s
     */
    String(const String &s) : String(s._v){};

    String(String &&s) : String(s._v)
    {
        delete[] s._v;
        s._v = new char[0]();
    }

    /**
     * @brief Wypisuje String
     *
     */
    void print() const { operator<<(std::cout, *this); }

    String &clone() const override
    {
        String *s = new String(*this);
        return *s;
        // return static_cast<Greater &>(klon);
    }

    /**
     * @brief Porownuje String
     *
     * @param g1
     * @return true
     * @return false
     */
    bool operator<(const Greater &g1) const override
    {
        const String &s1 = static_cast<const String &>(g1);
        return strcmp(_v, s1._v) < 0;
    }

    /**
     * @brief Kastuje String na char *
     *
     * @return char *
     */
    operator char *() const { return _v; }

    /**
     * @brief Przypisuje String
     *
     * @param s
     * @return String&
     */
    String &operator=(const String &s)
    {
        if (this == &s)
            return *this;

        delete[] _v;

        unsigned int len = strlen(s._v);
        _v = new char[len + 1]();
        strcpy(_v, s._v);

        return *this;
    }

    /**
     * @brief Wypisuje String
     *
     * @param os
     * @param s
     * @return std::ostream&
     */
    friend std::ostream &operator<<(std::ostream &os, const String &s)
    {
        os << s._v;
        return os;
    }

    /**
     * @brief Usuwa String z pamieci
     *
     */
    ~String()
    {
        delete[] _v;
    }
};

/**
 * @brief Max Greater
 *
 * @param a
 * @param b
 * @return const Greater&
 */
const Greater &max(const Greater &a, const Greater &b);

/**
 * @brief Max z tablicy Greater
 *
 * @param arr
 * @param size
 * @return Greater&
 */
Greater &max(Greater *arr, unsigned int size);

/**
 * @brief Zamienia Greater miejscami
 *
 * @param g1
 * @param g2
 */
void swap(Greater &g1, Greater &g2);