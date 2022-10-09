#pragma once

class Sum
{
private:
    double _v;

public:
    Sum() : _v(0){};

    double value() const { return _v; };
    void operator()(double v) { _v += v; };
};
