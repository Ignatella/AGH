#include <iostream>

struct Int_t
{
  Int_t() = default;
  Int_t(int v) : _v(v) {}

  operator int() const { return _v; }

  int &get() { return _v; }
  int get() const { return _v; }

  int &set(int v)
  {
    _v = v;
    return _v;
  }

private:
  int _v = 0;
};

#include "vec.h"

int main()
{
  vec v;

  v.push_back(Int_t{});
  v.push_back(Int_t{1});
  v.push_back(Int_t{2});

  for (const auto &_v : v)
    std::cout << _v << " ";

  v[0] = 5;
  v[1] = v[2] = v[0] * 2;
  v[2] = v[2] + 1;

  for (const auto &_v : v)
    std::cout << _v << " ";
}
/* output:
0 1 2 5 10 11
*/