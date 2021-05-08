# Lab_7 Tasks

### Array of functions

Analyze example.c, extend it by an x^(-2) function, for ten arbitrarily defined function arguments ( e.g. for ten
consecutive even numbers), print calculated results of the execution of all, available in the array, functions.

```c
#include <stdio.h>
#include <math.h>

double ff(double x){
	return 1+x*x;
}

int main(void){
	double (*p[])(double) = {sin,cos,ff,NULL};
	double (**q)(double) = p;
	while(*q) printf("%.4f\n", (*(*q++))(1.0));
	return 0;
}
```

--- 

### Pointers to function

Define a function that returns the sum of two integers, and a function that returns the greater of two integers. Let the
function prototypes be:

```c 
int add(int * , int *);
int comp(int * , int *);
```

Define function:

```c 
int add_or_comp (...),
```

whose arguments are: two pointers to integers & a pointer to a function that takes two pointers to int and returns a
value of type int. In the main() function, get two integer values & call `add_or_comp` passing values & pointer to the
target function.

--- 

### Pointer to !factorial function

Write and test two factorial functions!
Functions perform calculations in two ways: iteratively and recursively. Pass value for which factorial should be
calculated and string that characterize what function should be run. Example call `/a. out 12 recursion`. Use a pointer
to a function to call one of the methods according to client choice. The printout of the recursive version should look
like this:

```text 
value k =5, address k= 0x7ffcd85c118c
. value k =4, address k= 0x7ffcd85c115c
. . value k =3, address k= 0x7ffcd85c112c
. . . value k =2, address k= 0x7ffcd85c10fc
. . . . value k =1, address k= 0x7ffcd85c10cc
. . . value k =2, address k = 0x7ffcd85c10fc result value = 2, address wyn=0x7ffcd85c1108
. . value k =3, address k = 0x7ffcd85c112c result value = 6, address wyn=0x7ffcd85c1138
. value k =4, address k = 0x7ffcd85c115c result value = 24, address wyn=0x7ffcd85c1168
value k =5, address k = 0x7ffcd85c118c result value = 120, address wyn=0x7ffcd85c1198
120
```

--- 
