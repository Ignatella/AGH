# Lab_4 Tasks

### Squash arrays without duplicates

Please write a program where you create two ascending sorted tables `arr1` 
and `arr2` with size from the range `(5; 20)` filled with random numbers 
in the range `(0; 10)`. Then merge the tables into a new `arr` table, 
which will be sorted in ascending order and will `not` contain repeating items. 
```
Example
arr1 -> {0, 2, 2, 5, 7, 7, 10}
arr2 -> {0, 1, 1, 2, 4, 6, 6, 8, 8, 8, 9, 9}
arr-> {0, 1, 2, 4, 5, 6, 8, 9, 10} 
``` 
Please create a  `arr_ptr` array in order to assign
`arr1` , `arr2`, `arr`  and then list the elements of each array 
using the `arr_ptr` pointer.

--- 

### Pointers

Many simple operations on pointers :satisfied: Can be found in `lab4_IS_L2.pdf` file.

---

### Shift 2D array

Create a table of type `char arr[N][M]` where `N` and `M` are freely defined constants.
Using the `rand()` function to fill random arrays with `lowercase letters`, and then print
`arr[][]`. Write function `shift()` `void` type, which moves cyclically
elements of arrays in one position. The function works correctly for
any values of `N` and `M` . In the `main()` function create and execute the function enough
times to shift `arr` `p` item in the right, then print the table. The `p` value must be retrieved from the 
user.
```text
P < N * M
```
```text
Example

T[2][2]= {{ 'a','b'}, {'c', 'd'}} 
after execution P=2 
[c d]
[a b]
```
