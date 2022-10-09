#pragma once

/**
 * @brief Filtr kryterium. Sprawdza, czy jest podzielna przez x
 * 
 */
class DivisibleBy
{
private:
    /**
     * @brief Dzielnik
     * 
     */
    int _divisor;

public:
    /**
     * @brief Tworzy kryterium
     * 
     * @param divisor 
     */
    DivisibleBy(int divisor) : _divisor(divisor){};

    /**
     * @brief Sprawdza, czy argument jest podzielny przez dzielnik
     * 
     * @param divisible 
     * @return true 
     * @return false 
     */
    bool operator()(int divisible) { return divisible % _divisor == 0; };
};

/**
 * @brief Filtr kryterium. Spradza, czy liczba jest mniejsza od x
 * 
 */
class LowerThan
{
private:
    /**
     * @brief Liczba referencyjna
     * 
     */
    int _lowerThan;

public:
    /**
     * @brief Tworzy kryterium 
     * 
     * @param lowerThan 
     */
    LowerThan(int lowerThan) : _lowerThan(lowerThan){};

    /**
     * @brief Sprawdza, czy argument jest mniejszy od liczby referencyjnej
     * 
     * @param value 
     * @return true 
     * @return false 
     */
    bool operator()(int value) { return value < _lowerThan; };
};
