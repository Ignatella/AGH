# Before Lab_7 Tasks

1. ### Delete substring from sentence

Please write a program that will remove all 
instances of the substring from the sentence.

```C
Use:
char *strstr(const char *str1, const char *str2); (from <string.h>)
```

which returns a pointer to the first occurrence of `str2` in `str1`.
When `str2` is not present in string str1 function returns `NULL`
Example :

```Text 
Input:
Jak sie nie ma, co sie lubi, to sie lubi, co sie ma.

Substring: sie.

Output:
Jak nie ma, co lubi, to lubi, co ma.
```

2. ### Array flip over

Please write the program: `swap` function that swaps the values of two variables 
and then `flip_over` and test the `swap` function using an `flip_over` 
function that flips over a one-dimensional array of integers.

3. ### Combine 2 arrays

Please write and test the `combine` function that combines ascending arrays
into one array sorted in ascending order (without sorting).
