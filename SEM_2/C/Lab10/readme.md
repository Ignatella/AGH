# Lab_10 Tasks

### Read/Write `Struct complex { }` array from/to file

Create a struct `struct complex { }`. Create a function `printComplex()` that returns void, which takes as an argument
`struct complex *` and outputs the complex number in the form :

```text 
real + i * imaginary (e.g. 5.3 + i*15.0)
```

1) Create a `struct complexWrapper { }` structure that has 3 fields:

```text
complex,
module, 
pointer to function that accepts complex as an argument and returns void. 
```

Please allocate memory for a one-dimensional array of structures of the size specified by user, fill it with random
numbers. Set pointer to the `printComplex()` function. Write a void function that calculates module of complex number.
Print the array and save to a text file in the form:

```text
|(5.000000+8.000000*i)|=9.433981
|(4.000000+8.000000*i)|=8.944272
|(3.000000+11.000000*i)|=11.401754
|(6.000000+9.000000*i)|=10.816654
|(5.000000+10.000000*i)|=11.180340
|(7.000000+12.000000*i)|=13.892444
```

2) Use the `qsort()` function to sort an array of structures by modules. Print the result on the screen and save results
   to a text file.

--- 

### Typedef for functions & operations on functions array

Please write a program that calculates the values of the functions defined. Print function name that produces the
biggest result. Please define five functions :

```c
double fun0 (double x) { return log(x); }
double fun1 (double x) { return x*x; }
double fun2 (double x) { return exp(x) } 
double fun3 (double x) { return sin(x); }
```

1) Define the type `funcType`: pointer to a function that accepts a value of type double and returns double.
2) Define the type `funcArrType`: array of `funcType` functions.
3) Define the type `stringArr`: array of strings.
4) Define a `funmax()` function whose first argument is `funcArrType`, the function returns a pointer to the function
   for which the value calculated for the second argument (the given value of double `X`) is the largest.

In the `main()` function, create an instance of `funcArrType` type and initialize with pointers to the created
functions. Create an array of strings that contains the names of defined functions. Create an `FMAX` variable of type
`funcType` to assign a pointer to the function that returns the largest value for a given argument. Test the program for
arguments between `x=1` and values `x=10` with a step equal to `k=1` and print the results e.g. in the form:

```text
For the argument x=1.0, the largest value of 2.71828 is returned by the function exp(x).
```

Consider cases of equal max values for several functions.

--- 

### Add & Subtract long numbers

Write a program that adds and subtracts long numbers. Maximum length of the input operands can be `200 digits`. In the
main() function, perform calculations and print results.
--- 
