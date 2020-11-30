# Lab_3 Tasks

1. ### Sum big random integers

    Please implement the operation of adding long e.g.
    80-digit integers. The length of the number is read
    from the keyboard. Write the Program so that only 
    numbers longer than 40 digits but shorter than 90 
    digits are generated.
    
    Example of program operation for digit 5:
    ```
         73381801964326885910714966786835221868364467985895
    +
         89598849211524783172082363224591454810812333655900
        ---------------------------------------------------
        162980651175851669082797330011426676679176801641795
    ```
   
2. ### Swap The Array

    Please write a program that will create a 10-element array of real 
    numbers. Fill it with random numbers in the range [-100.0, 100.0]
    and print its contents using the %*format specifier.* f so that all
    values are aligned to the right and written with two digits after 
    the decimal point [ 10: 100 ] then, using the loop", invert the 
    array, i.e. replace the values of the elements so that the first 
    is replaced with the last,the second with the penultimate, and 
    write with two digits after the decimal point aligned to the 
    left edge along with the sign.
    WE DO NOT USE AN ADDITIONAL ARRAY

3. ### Count random dots
   Please write a program that random n floating point numbers from 
   the range [0.0, 9.9999] (the number n is to be read from the keyboard).
   In the table of integers with ten elements, calculate how many values 
   were drawn from each range: so that in the element tab[0] there is the
   number of drawn values from the range [0.0, 1.0), in tab[1] from the 
   range [1.0, 2.0), etc. The premium solution is binding the index of 
   the array with the range of consecutive ranges, that is, without the 
   if statement. At the end, please write the tab, e.g.:
    
    ```
    element[0] = 19.23 
    element[1] =-23.34
    element[2] = 14.01 
    element[3] =-83.09
    element[4] = 12.45 
    element[5] = 20.43
    element[6] = 12.34
    element[7] =-63.99
    element[8] =-42.68 
    element[9] = 93.66
    			 
    After swap:
    
    element[0] =+93.66 
    element[1] =-42.68
    element[2] =-63.99 
    element[3] =+12.34
    element[4] =+20.43 
    element[5] =+12.45
    element[6] =-83.09 
    element[7] =+14.01
    element[8] =-23.34 
    element[9] =+19.23
    ```
