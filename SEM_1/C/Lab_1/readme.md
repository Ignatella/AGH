# Lab_1 Tasks

1. ### Printf

    Please insert the printf statement in the appropriate place in the following program:

    ``` C
    # include < stdio.h>
    int n;
    int main(){
        int zm_1 = 4;
        int zm_3 = 7;
        {
            int zm_2 = 10;
            int zm_3 = 6;
            int n = 12;
            zm_3 = zm_3 +1;
            zm_1 = 6;
        }
        zm_3 = zm_3 + 1;

        return 0;
    }
    ```
   
    So that the result looks like this:

    > variable n = 0, variable zm_2 = 10

    > variable n = 0, variable zm_3 = 7

    > variable n = 12, Variable zm_3 = 7

    > variable zm_1 = 4, variable zm_3 = 7

    > variable n = 0, variable zm_3 = 8

    > variable zm_1 = 6, variable zm_3 = 7, variable zm_2 = 10

2. ### Dividers of 4

    Please write a program that will write on the screen all the numbers divisible
    by 4 and undivided by 5 from the range from -5 to 98, and then write how many there are.

3. ### Random numbers stats
    Please write a program that draws 20 pseudo-random numbers from the range from
    118 to 286, prints the smallest and largest and arithmetic mean of the drawn
    numbers on the screen.
4. ### Banknotes
    Please write a program that will load the amount, and then write out how to
    "withdraw" it with a minimum amount of banknotes. We have at our disposal
    banknotes in denominations of 20, 10 and 5.