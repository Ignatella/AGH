# Before Lab_3 Tasks

1. ### Binary -> Decimal

   Please write a program that reads 8 characters 
   (they should be zeros or ones), then writes them 
   using the format %s. then, in the program, replace 
   the string representing the binary notation of a
   number in NBC with an unsigned integer in decimal.
   Operator ? : should be used.   
   
2. ### Decimal -> Binary

   Please write a program that will print a binary
   representation of the loaded integer on the screen.
   !!! Use bitwise operations. Use the 9-character
   array char number [9] for writing. Verify that 
   the number you are reading can be written to 8
   bits. Array Element number[8]='\0' The program 
   is supposed to load a number and write its 
   conversion (as a string of characters).

   ```C
   char liczba[9]; //konwertujemy liczby z zakresu ?
   int numer;
   //wczytanie liczby i sprawdzenie czy jej reprezentacja 
   bitowa  zmiesci sie w tablicy
   
   ........
   ........
   ........
   printf ("liczba %d zapis binarny %s", numer,liczba); //liczba 11 zapis binarny 00001011
   ```

3. ### Count of 1 in number
   
   Please write a program that will count the number
   of bits set to 1 in the given number.!!! Use
   bitwise operations.
   
   ```C
   #include <stdio.h>

   int main ()
   {
      unsigned int  liczba ;
      ................    // deklaracja pozostalych zmiennych 
      // wczytanie wartosci - np. 19 
      do{
         ....................
         ................
      }while(......);
      printf("Liczba %d ma bitow ustawionych na 1: %d \n",liczba, wynik);  // Liczba 19 ma bitow ustawionych na 1: 3 
      
      return 0;
   }
   ```
    
4. ### SortEvenAndOdds
   
   Please write a program that converts the order
   of elements of the array of integers in such a
   way that even elements are at the beginning, 
   and odd elements at the end of the array (you
   do not need to keep the order of occurrence of
   numbers) - we load the size of the array from 
   the keyboard, we draw values from the range 
   <0, 100>. We treat zero as an even number.

   ```C
   Before:
   element[0] = 19
   element[1] = 23
   element[2] = 14  
   element[3] = 83
   element[4] = 12  
   element[5] = 20
   element[6] = 12
   element[7] = 63
   element[8] = 42  
   element[9] = 53
   
   After:
   element[0] = 42
   element[1] = 12
   element[2] = 14
   element[3] = 12
   element[4] = 20
   element[5] = 83
   element[6] = 63
   element[7] = 23
   element[8] = 53
   element[9] = 19
   ```
   