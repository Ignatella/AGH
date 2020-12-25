###TASK:

The next (at least two) elements of the list with the 
same value are called a submarginal constant.
Please write a function that removes the longest constant 
sublist from the input list. The condition for removing 
it is that it exists in the list exactly one of the
longest permanent sublist. The function must pass a 
pointer to the first item in the list. The function should
return the number of deleted items. 

For example:
```Text
from the list [ 1 3 3 3 5 7 11 13 13 1 2 2 2 2 3 ] remove sublist [ 2 2 2 2 ]
from the list [ 1 3 3 3 3 5 7 11 13 13 1 2 2 2 2 3 ] do not remove anything.
```
