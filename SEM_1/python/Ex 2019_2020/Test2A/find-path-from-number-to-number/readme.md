###TASK:

There are three operations on the set of integers:
```Text
A,B,C transforming numbers:

A: increases the number by 3;
B: doubles the number;
C: all even digits in the number increases by 1, e.g. 2356->3357, 1999->1999.
```

Please write a function that checks if you can convert
the number x to the number y in no more than N steps.
The function should pass the values X, Y, N, the 
function should return the number of possible sequences
of operations converting the number x to y (or the value
0 if there is no such conversion). Note: it is forbidden
using two of the same operations consecutively.

```Text
For X = 11, Y = 31, N = 4 => Output = 3 [ABA  ACBC CABA]
For X = 11, Y = 32, N = 4 => Output = 0
```
