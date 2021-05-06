# Lab_5 Tasks

### Sieve of Eratosthenes

The "Sieve of Eratosthenes" method is used to detect prime numbers. It allows you to find all prime numbers that are
less than a given value of N.

Algorithm:

1) Create an array from 1 to N.
2) Remove number 1.
3) Search starting from the last found primary number (the first time from 1) the nearest unspecified number. This
   number is the first. Delete from the list all numbers divisible by this primary number.
4) Repeat step 2) until found primary number will be greater than N^(1/2)
5) All remaining numbers are primary numbers.

Task:

Please implement `Sieve of Eratorosthenes` algorithm. Write a function that will dynamically declare an array of numbers
with the specified size, fill it with some value e.g. one ‘1’ (Use memset()) and return pointer that points to the
allocated array. You should operate on indexes. At the end of program the array should look like the following:
values under indexes that are not primary numbers should be set to 0.

Additional task:

Create an array that contains only first numbers.

--- 

### Read string from stream

Create an 80-character array. Read from user any string into the array. Repeat reading using the function: scanf(),
gets(), fgets(). Save input string into the file: `file.txt`. Execute the program now by redirecting the stdin input
stream as follows a.out < characters.txt and read the string using scanf() and then fgets().

### Sort & normalize

Using the arguments of the main() function, specify the size of the 2D array in the command line, and the range for
random numbers with that you will fill the array. Make a dynamic memory allocation and verify that the allocation has
been made correctly (if not, terminate the program). Create an array and fill it with random numbers from the specified
range. Write the function that will sort and normalize the array normalize so that the sum of all elements will be equal
to 1.

---