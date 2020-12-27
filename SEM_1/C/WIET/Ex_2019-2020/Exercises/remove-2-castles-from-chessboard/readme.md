###TASK:

Given an array: 

```C
int t[N][N] (representing a chessboard) 
```

filled with natural numbers. In each column there is exactly
one tower, whose number the row contains an array:

```C
w[N]
```

Please write a function that selects 2 towers to remove from the 
chessboard, so that the sum of the rest numbers on the chessboard
was the smallest. The function should return the column numbers
from which the towers were removed. Note - assume that the tower
checks the entire row and column except the field on which it is placed.
