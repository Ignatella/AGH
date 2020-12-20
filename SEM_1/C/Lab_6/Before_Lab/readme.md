# Before Lab_6 Tasks

1. ### Bisection search

   Write a recursive function that finds the number x in
   ascending order array by bisection method.

   ```C
   int find(int *array, int count, int x);
   ```

   The function returns 1 if the value is found, 0 otherwise.
   Please test the function on an array
   
   ```C
   int tab_A[] = {1,3,5,6,7,9,11,13,16,22,25,34,35,36,37,45,46,47,47,47,55,56,58,59};
   ```
   
2. ### Fibonacci [iteration]

   In the main () function, using the scanf() function,
   get the number for which the nth Fibonacci string 
   expression is calculated using the iterative function.

3. ### Recursive Fibonacci tree

   The nth expression of the Fibonacci string is 
   calculated using the recursion function. In the
   main () function, using the scanf() function, get
   the number for which the nth expression of the 
   Fibonacci string will be calculated using a recursive
   function that will output the recursive call tree.
   We don't use global variables. Result for value 6:
   
   ```Text
   Depth(points), Process, l=call count
   0, Count f(6)=f(5)+f(4), l=1
   1., Count f(5)=f(4)+f(3), l=2
   2.., Count f(4)=f(3)+f(2), l=3
   3..., Count f(3)=f(2)+f(1), l=4
   4...., Count f(2)=f(1)+f(0), l=5
   5....., Return f(1), l=6
   5....., Return f(0), l=7
   4...., Return f(1), l=8
   3..., Count f(2)=f(1)+f(0), l=9
   4...., Return f(1), l=10
   4...., Return f(0), l=11
   2.., Count f(3)=f(2)+f(1), l=12
   3..., Count f(2)=f(1)+f(0), l=13
   4...., Return f(1), l=14
   4...., Return f(0), l=15
   3..., Return f(1), l=16
   1., Count f(4)=f(3)+f(2), l=17
   2.., Count f(3)=f(2)+f(1), l=18
   3..., Count f(2)=f(1)+f(0), l=19
   4...., Return f(1), l=20
   4...., Return f(0), l=21
   3..., Return f(1), l=22
   2.., Count f(2)=f(1)+f(0), l=23
   3..., Return f(1), l=24
   3..., Return f(0), l=25
   rFibonacci (6) = 8
   ```
    
4. ### Fibonacci with 'memory'

   Please complete the function from the previous
   task with a local array that stores in the i-th
   cell the i-th Value of the Fibonacci string.
   At the beginning of the action:

    ```C
    .tabf[0]=0, tabf[1]=1.
    ```

   Every time you call a recursive function, check that the value has been
   already calculated and is in the array, if so then you need to use it, if not then calculate and save
   to the board. Please print the call tree.
   Result for value 6:
   
    ```text
   Depth(points), Function, l=call count
   0, Count f(6)=f(5)+f(4),l=1
   1., Count f(5)=f(4)+f(3),l=2
   2.., Count f(4)=f(3)+f(2),l=3
   3..., Count f(3)=f(2)+f(1),l=4
   4...., Count f(2)=f(1)+f(0),l=5
   5....., Return f(1),l=6
   5....., Return f(0),l=7
   4...., Return f(1),l=8
   3..., Return f(2),l=9
   2.., Return f(3),l=10
   1., Return f(4),l=11
    ```
