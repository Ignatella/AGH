# Lab_2 Tasks

1. ### Complete program

Please complete the program that follows these instructions. Wherever possible use the pointer.

```c
#include
<stdio.h>
#define
N ...........
.........suma(.........., ..............);
int main(void){
//deklaracja tablicy 10 liczb całkowitych, użyj N
//deklaracja wskaźnika p do liczby całkowitej, użyj NULL
//przypisz kolejnym elementom tablicy liczby pseudolosowe z przedziału od
//10 do 35 i wypisz je na ekran,
//nie używaj zmiennej int i do indeksowania tablicy
for (...=tab; .... <... + N; ...++){
....=rand()......;//użyj p, nie korzystaj z tab
//korzystając z p oraz tab oblicz wartość indeksu kolejnych elementów tablicy,
//wypisz wartości kolejnych elementów używając p
printf("p[%d]=%d\n", .............., ...............);
}
printf("\n");
//używając funkcji suma() oblicz sumę elementów tablicy z wybranego zakresu
// (np. od elementu 2 do N/2)
// Proszę sprawdzić czy zakres jest poprawnie podany przez użytkownika, wypisać
// sumowane  wartości, a następne wyliczyć sumę
int sum = suma(............., ..............);
// wypisać sumę oraz przedział wartości
return 0;
}
..... suma(const ......, const ......){
.........................
….......................
return .....................;
}
```

--- 

2. ### Pointers

Declare two arrays of length `N1` and an array of length `N2`, fill them with random numbers from `(0,1)`. Create an
array of length `n1 + n2`.

1) Sort both arrays using the sorting function, (could be a function from the previous lab).
2) Write the function `swap(...)` of type void, which swaps the values passed to its two arguments. Test the function by
   calling it for arbitrary values of two variables. Write out the values of the variables before and after the function
   call.
3) Write an `inverse()` function to invert a one-dimensional array using `swap()`.
4) Write the  `swapTables(...)` function to swap the contents of two one-dimensional arrays with same length. Use the
   `swap()` functions.
5) Write a function that merges two sorted arrays into one sorted array. Function accept the addresses of all three
   arrays and the lengths of the two sorted arrays.

c) d) and e) perform again using only pointers

---

3. ### Guess Random Value

Please write a program that will guess the random number. In the first step, the program randoms the number
from `0 to 100`. Then we create a loop in which the program guesses for what number. In the loop random the value for
variable `try` from the range from `0 to 100`. If the `try` is equal `the hidden number`, end the program. If not then
check whether the `try` is smaller or larger than the `the hidden number`. Based on the comparison of the variables,
limit the range from which it will be another value randomized. How many steps does the program need to guess the number
? Repeat the operation 1000 times, and calculate the average number of attempts.