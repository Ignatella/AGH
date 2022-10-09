#pragma once

#include <functional>
#include <vector>

class FilterCriteria
{
private:
    std::vector<std::function<bool(int)>> _v;

public:
    FilterCriteria() : _v(std::vector<std::function<bool(int)>>{}){};

    void add(std::function<bool(int)> f) { _v.push_back(f); };
    unsigned int size() const { return _v.size(); };
    std::function<bool(int)> get(unsigned int i) const { return _v[i]; };
};
