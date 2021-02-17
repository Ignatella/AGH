### Loops in multidimensional array

An

```text
int tab[n][n]
```

filled with natural numbers is given. Write a function that, for a given array, finds a row in which the elements repeat
cyclically, e.g. `2,5,7,2,5,7,2,5,7,2,5,7,2,5,7,2,...` or `1,4,2,2,5,7,1,4,2,2,5,7,1,4,2,2,...` It can be assumed that
the cycle length is greater than 2 and less than N / 2. An array should be passed to the function, the function should
return the row number with this property, or -1 if there is no such row.
