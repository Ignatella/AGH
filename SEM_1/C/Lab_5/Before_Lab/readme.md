# Before Lab_5 Tasks

1. ### Math from arguments

   Please write a program that will be called
   with three arguments : two integers and an
   arithmetic operation symbol (addition,
   subtraction, multiplication, division, 
   division modulo). The Program should be
   designed to respond to incorrect data.
   Example call:

    ```text
    ./a.out 7 6 +
    ```
    Result
    ```C
    7 + 6  = 13
    ```
   
2. ### ToLower()

   Please finish the program which converts
   the uppercase letters into lowercase letters
   in the string. Please write the program without
   using the strlen() and sizeof () functions
   and without creating a new string. You can 
   use the uppercase to lowercase function.
   
   ```C
   #include ....
   #include ....
   int main(void){
      .......
      .......
      printf("Lancuch oryginalny: a->........\n",........);
      .........
      .........
      printf("Lancuch zmieniony: a->.........\n",........);
   
      return 0;
   }
   ```

3. ### Searching For Rand Letter

   In the main function, declare a one-dimensional array 
   randLetters of length = 10 and fill it with random 
   lowercase letters to form a string of characters. Then
   random letter. Using the strchr() function (from the
   <string.h>), please check if the random letter is in
   the array string. If it was found then please print the
   index of the first occurrence of the random letter in 
   the string on the screen and check how many times it
   occurs in the random string. All the time please use
   the strchr() function. If the sign does not appear 
   please write the appropriate message.
    
4. ### Swap Arguments
   Please complete the program so that you get the following
   result. Do not use loops, only functions from the <string.h>. 
   Call example:

    ```text
    ./a.out One Two
    ```
   Result:
    ```text
    Before: One Two
    After: Two One   
    ```
   ```C
   int main(.............) {
      .........
      .........
      printf ("Before: %s %s\n", nap1, nap2);
   
      .........
      .........
      
      printf ("After: %s %s\n", nap1, nap2);
      return 0;
   }
   ```
