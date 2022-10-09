#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <exception>

std::string print(bool c)
{
    return c ? "Znalezione" : "Nie znalezione";
}

std::string operator*(const std::string &s, const int &i)
{
    std::string result = "";
    for (size_t j = 0; j < i; j++)
    {
        result += s;
    }

    return result;
}

std::string operator*(const int &i, const std::string &s)
{
    return s * i;
}

template <typename K, typename V>
class Assoc
{
private:
    std::vector<K> _keys = std::vector<K>{};
    std::vector<V> _vals = std::vector<V>{};

public:
    void insert(K key, V val)
    {
        _keys.push_back(key);
        _vals.push_back(val);
    };

    void print(std::string prefix) const
    {
        for (auto it = std::begin(_keys); it != std::end(_keys); it++)
        {
            size_t i = it - std::begin(_keys);
            std::cout << "--- " << prefix << " --- klucz: " << *it << " wartosc: " << _vals[i] << std::endl;
        }
    }

    bool contains(K key) const
    {
        auto it = std::find(std::begin(_keys), std::end(_keys), key);

        return it != std::end(_keys) ? true : false;
    }

    V &operator[](K key)
    {
        auto it = std::find(std::begin(_keys), std::end(_keys), key);

        if (it != std::end(_keys))
        {
            size_t i = it - std::begin(_keys);
            return _vals[i];
        }

        insert(key, V());

        return _vals[_vals.size() - 1];
    }

    const V &operator[](K key) const
    {
        auto it = std::find(std::begin(_keys), std::end(_keys), key);

        if (it != std::end(_keys))
        {
            size_t i = it - std::begin(_keys);
            return _vals[i];
        }

        throw std::invalid_argument("Key not found");
    }
};
