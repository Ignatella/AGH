# Lab_3 Tasks

1. ### Squash tables

Please write a program where you create two one-dimensional arrays of type 
`int arr1` and `arr2` of the same arbitrary length `K`. 
Write the `print_tab()` function to write any one-dimensional array (use 
index notation).
Write a function to which you will pass the created two one-dimensional arrays of the same 
length `K` and create a two-dimensional array int `arr[3][K]` with three lines; a number
columns = length of one-dimensional arrays.
In the first row you enter the elements of `arr1`, in the second the elements of `arr2`, 
and to the third sum of elements with the same indexes from both arrays. 
Print the array in rows using the `Tab[i][j]` index notation once, and the second time 
`*(*(Tab+i)+j)` notation, print the table by columns in the form :

```c
I column
arr[1][1] = value *(*(T +1) +1)= Address value Tab [1][1]
arr[2][1] = value *(*(T +2) +1)= Address value Tab [2][1]
etc.

II ........... etc........
```

Print the Tab in rows using the `print_tab()` function.

---

2. ### Diagonal

In the `main()` function, create a square array of type int with the dimension specified by
user and initialize random values from the specified range.
Write the `sum_i(...)` function to which you will pass the created array. `sum_i` should perform:

* the sum of all elements in the prime diagonal
* the sum of the elements over the prime diagonal
* the sum of the elements on the main diagonal

Test the program for arrays with dimensions of 3x3 and 5x5 and values in the range (1:10)

---

3. ### Matrix multiplication

In the `main()` function, create two two-dimensional arrays, each of size `[m][n]`, 
initialize them with random values `from -5.0 to 5.0` write to screen a 
then multiply the two arrays by each other and print the arrays containing 
score.
