//Extremely simple vector and matrix classes by Janusz Malinowski. 
#include <stdio.h>
#pragma once
class Vector4
{
 public:
 double data[4];
 Vector4();
 void Print(void);
 void Set(double d1,double d2,double d3);
 double GetX();
 double GetY();
 double GetZ();
 Vector4 operator-(const Vector4 &);
 friend Vector4 operator*(const Vector4 &,double);
};

class Matrix4
{
 public:
 double data[4][4];
 Matrix4();
 void Print(void);
 Matrix4 operator*(const Matrix4);
 friend Vector4 operator*(const Matrix4,const Vector4);
};


