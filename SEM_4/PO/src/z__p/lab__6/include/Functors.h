#pragma once

class DivisibleBy
{
private:
    int _divisor;

public:
    DivisibleBy(int divisor) : _divisor(divisor){};
    bool operator()(int divisible) { return divisible % _divisor == 0; };
};

class LowerThan
{
private:
    int _lowerThan;

public:
    LowerThan(int lowerThan) : _lowerThan(lowerThan){};
    bool operator()(int value) { return value < _lowerThan; };
};
