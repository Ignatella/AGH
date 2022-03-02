#include "Fraction.h"
#include <iostream>

int nwd(int m, int n)
{
  m = abs(m);
  n = abs(n);
  int oldm, oldn;
  while (m % n != 0)
  {
    oldm = m;
    oldn = n;
    m = oldn;
    n = oldm % oldn;
  }
  return n;
}

void Fraction::simplify()
{
  int n = nwd(l, m);
  l = l / n;
  m = m / n;
}

std::ostream &operator<<(std::ostream &os, const Fraction &f)
{
  int i = f.l / f.m;

  if (i != 0)
  {
    if (abs(f.l - f.m * i) == 0)
      os << i;
    else
      os << i << " " << abs(f.l - f.m * i) << "/" << abs(f.m);
  }
  else
    os << f.l << "/" << f.m;

  return os;
}

Fraction &Fraction::operator*=(const Fraction &f)
{
  this->l *= f.l;
  this->m *= f.m;
  simplify();
  return *this;
}

Fraction &Fraction::operator-=(const Fraction &f)
{
  this->l = this->l * f.m - f.l - this->m;
  this->m *= f.m;
  simplify();
  return *this;
}
