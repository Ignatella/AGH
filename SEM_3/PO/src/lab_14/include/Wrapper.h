#pragma once

#include <cstring>
#include <iostream>

/**
 * @brief Kopiuje jeden string do drugiego
 * 
 * @param dest 
 * @param source 
 */
void copyStrTo(char **dest, const char *source)
{
    *dest = new char[strlen(source) + 1]();
    strcpy(*dest, source);
}

/**
 * @brief Przedstawia wrapper
 * 
 */
class Wrapper
{
protected:
    /**
     * @brief Typ wrappera
     * 
     */
    char *t;

protected:
    /**
     * @brief Tworzy wrapper z typem
     * 
     * @param t 
     */
    Wrapper(const char *t)
    {
        copyStrTo(&this->t, t);
    };

public:
    /**
     * @brief Wypisuje wrapper
     * 
     * @param os 
     */
    virtual void print(std::ostream &os) const = 0;

    /**
     * @brief Zwraca typ wrappera
     * 
     * @return const char* 
     */
    virtual const char *type() const { return t; };

    /**
     * @brief Wykonuje ++ na wrapperze
     * 
     */
    virtual void operator++(int) = 0;

    /**
     * @brief Usuwa wrapper z pamieci
     * 
     */
    virtual ~Wrapper() { delete[] t; };
};

/**
 * @brief Wpapper nad intem
 * 
 */
class IntWrapper : public Wrapper
{
private:
    /**
     * @brief wartosc ktora przechowuje wrapper
     * 
     */
    int v;

public:
    /**
     * @brief Tworzy IntWrapper
     * 
     * @param v 
     */
    IntWrapper(int v) : IntWrapper::Wrapper("Int"), v(v){};

    /**
     * @brief Wypisuje wrapper na ekran
     * 
     * @param os 
     */
    void print(std::ostream &os) const override { os << v; };

    /**
     * @brief Wykonuje ++ na wrapperze
     * 
     */
    void operator++(int) override { v++; };
};

/**
 * @brief Wrapper nad stringiem
 * 
 */
class StringWrapper : public Wrapper
{
private:
    /**
     * @brief Warosc ktora przechowuje wrapper
     * 
     */
    char *v;

public:
    /**
     * @brief Tworzy wrapper
     * 
     * @param v 
     */
    StringWrapper(const char *v) : IntWrapper::Wrapper("String") { copyStrTo(&this->v, v); };

    /**
     * @brief Wypisuje wrapper na ekran
     * 
     * @param os 
     */
    void print(std::ostream &os) const override { os << v; };

    /**
     * @brief Wykonuje ++ na wraperze
     * 
     */
    void operator++(int) override
    {
        for (int i = 0; i < strlen(t); i++)
            t[i] = toupper(t[i]);
    };

    /**
     * @brief Usuwa StringWrapper z pamieci
     * 
     */
    ~StringWrapper() override
    {
        delete[] v;
    };
};

/**
 * @brief Wrapper nad float
 * 
 */
class FloatWrapper : public Wrapper
{
private:
    /**
     * @brief Wartosc ktora przechowuje wrapper
     * 
     */
    float v;

public:
    /**
     * @brief Tworzy FloatWrapper
     * 
     * @param v 
     */
    FloatWrapper(float v) : IntWrapper::Wrapper("Float"), v(v){};

    /**
     * @brief Wykonuje ++ na wraperze
     * 
     */
    void operator++(int) override { v++; };

    /**
     * @brief Wypisuje FloatWrapper
     * 
     * @param os 
     */
    void print(std::ostream &os) const override { os << v; };
};
