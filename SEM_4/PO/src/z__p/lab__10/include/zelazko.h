#pragma once

#include <iostream>

class Zelazko
{
protected:
    int _upperBound;
    int _temp;

    Zelazko(int upperBuond, int temp = 0) : _upperBound(upperBuond), _temp(temp){};

public:
    Zelazko() = delete;
};

class ZelazkoPhilips : public Zelazko
{
private:
    int _price;

public:
    ZelazkoPhilips(int price) : Zelazko(5), _price(price){};

    void UstawTemperature(int temp)
    {
        if (temp > _upperBound)
            return;

        _temp = temp;
    };

    void Wypisz() const
    {
        std::cout << "Philips cena: " << _price << ". temperatura: " << _temp << "." << std::endl;
    };
};
