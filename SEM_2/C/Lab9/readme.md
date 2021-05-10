# Lab_9 Tasks

### `Struct complex { }`

Create a struct `struct complex { }` to store complex numbers. Create two variables of `complex` type in the `main()`
function. Use scanf() to assign values to them. Print the structs as following:

```text
z1 = 3 + 5*i
z2 = 4 + 6*i
```

Write a function `calculator()` that performs basic arithmetic operations on the `complex` numbers. Pass 2 structures
and operation type. In the main() function, call the calculator() function for all defined operations and print the
results.

--- 

### `Union` & `qsort()`

Create a structure `struct number { }` that has two fields:

```text
char type;
union {
    int intVal;
    double fVal
 }
```

A character variable takes one of two values 'i' or 'd' according to variable type stored in union. Create an array of
100 structures. With equal probability, fill them with integers and real values in the range from -5 to 5. Write a
function that prints the array (value and type). Implement a sort function that uses the `qsort()` function to sort
array as following: move integers to the first part of the array, and doubles to the second part of the array. Test the
operation for three data sets. Print the sorted array and average of all printed numbers.

--- 

### Cycle list

Create a structure that has two fields:

```text
character;
pointer to the next structure. 
```

Create 3 variables (a, b, c) of type structure ... Let variable a point to b, variable b points to c, and variable c
points to a.

1) Using variable a and the corresponding fields, set the character field in a, b, c.
2) Using variable b and the corresponding fields, print the character field of variables a, b, c.
3) Using variable c and the corresponding fields, replace the lowercase letter with the uppercase letter in the
   character field of variables a, b, c.

--- 
