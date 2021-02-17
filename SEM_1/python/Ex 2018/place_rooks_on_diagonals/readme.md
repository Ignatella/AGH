### Place rooks on diagonals

Given is an array

```text
int t [n][n] 
```

filled with integers. This array represents a chessboard on which both diagonals are occupied by towers. Please write a
function that checks if you can remove some of the towers so that: (1) the sum of the values of the fields covered by
the other towers is zero, (2) there is one tower in each row, and (3) there are the same number of towers on each
diagonal. An array must be passed to the function, the function must return a `Boolean` value.