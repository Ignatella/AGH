# Lab_8 Tasks

### Read array of structures from the stream & sort them

Create a structure `struct client {}` that contains fields:

```text 
first name (char[20]),
last name (char[32]), 
postal code(as a character string),
age
```

Create a five-element array of structures, and then from an example text file (you can write it manually, min 5 clients)
we read clients into the array structures redirecting input stream. Use qsort() to sort the clients in ascending order
by the last name and then by first name.

--- 

### `Bsearch()` pointer and number

In the program, create a structure `struct vector`, and `struct abc` that has three fields:

```text 
vector,
length of the vector,
tolerance field. 
```

Create an array of 10 ABC structures. Fill with random numbers vector field. Write a function that based on the vector
field complement the vector length field, and the tolerance field (defined below)

Use the bsearch() function to find all vectors with vector length `d` with a user-specified (in percent)
tolerance `t` . Look for vectors whose lengths are in the range.

```text
[d - (t percent of d value); d + (t percent of d value)]
```

Please print on the screen the array of structures, before and after sorting and found vectors with suitable lengths.

--- 

### Pointer to !factorial function

Please write a function with a variable number of arguments:

```text 
....... mergeArrs (........);
```

to which we can pass any number of one-dimensional arrays, of any size. The function returns a pointer to a
two-dimensional array whose rows will be the arrays passed to the function. Please test the function for the given array
sets and print results.

Input

```text
int tab_A[] = {3, 2, 5, 4}; 
int tab_B[] = {12, 10, 13, 12, 18, 7};
int tab_C[] = {22, 20};
```

--- 
