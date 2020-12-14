# Lab_5 Tasks

1. ### Sum & Product of consecutive arr values

   Please write functions compatible with prototypes :

   ```Text
   1) ........ sum (float * first, int n);
   2) ........ product (flat * first, float * last);
   ```
   
   1) Counts the sum of n consecutive array elements 
      from the first pointer .
   2) Counts the product of successive array elements
      from the first pointer to the last pointer inclusive.
   In the main function, declare a 100 element array of 
   real numbers and fill it with consecutive numbers 
   starting from -3.0 with step 0.07. Using the sum 
   and product functions, please write:
      
            a) Sum and product of all elements of the array
            
            b) Sums and products of elements in the next 10 elements.
   
   Outcome of the program:

   ```Text
   suma wszystkich elementow = 46.6, iloczyn wszystkich elementow ...
   -------------------------------------------------------------
   elementy od  0 do  9 suma = -26.85, iloczyn = 312899,735948800
   elementy od 10 do 19 suma = -19.85 , iloczyn = 901,822072597
   elementy od 20 do 29 suma = -12.85, iloczyn = 10,831112665
   elementy od 30 do 39 suma =  -5.85, iloczyn = 0,002413267
   elementy od 40 do 49 suma =   1.15, iloczyn = -0,000000002
   elementy od 50 do 59 suma =   8.15, iloczyn = 0,093670760
   elementy od 60 do 69 suma =  15.15, iloczyn = 58,246222957
   elementy od 70 do 79 suma =  22.15, iloczyn = 2727,174802876
   elementy od 80 do 89 suma =  29.15, iloczyn = 43252,480910814
   elementy od 90 do 99 suma =  36.15, iloczyn = 375272,979868484
   ``` 

2. ### Partial negation

   Please write a program that accepts an unsigned int number 
   from the user. Use bit operators and bit masks to negate 
   the left (more significant) half of the number. Enter the 
   mask value and the new number value. The program should work
   universally, regardless of the hardware: first check how many
   bits the type occupies, and on this basis create a mask that
   will help to negate the first half of the bits.

   ```Text
   e.g.:
   Dla liczby 1234567890 wynikową wartością będzie: 3060335314
   Dla liczby 65535 wynikową wartością będzie: 4294967295
   ```

3. ### Sum, Product, Average func

   Write a function fun_1 that random n integers (n is a 
   function parameter) from the range [0, 15] and calculates 
   their sum, product, and average. The function should not write
   anything. In the main function, you need to get the number of
   draws n from the user, call the fun_1 function and write the
   calculated values of sum, product and average. Note: these
   values must be written only in the main() function.
