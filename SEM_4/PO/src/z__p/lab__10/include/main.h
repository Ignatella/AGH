#pragma once

class Produkt
{
protected:
    int _price;

protected:
    Produkt(int price) : _price(price){};

public:
    Produkt() = delete;
};
