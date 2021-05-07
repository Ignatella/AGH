# Lab_5 Tasks

### Count word occurrences

Please read & print input from stdin (redirect stream ./a.out < file.dat). Write a program that reads the
file `file file.dat` and counts the number of occurrences of a word specified as a program argument. The program will
display only these lines text that contains the specified string. Please count the number of lines written out. Please
complete the task for the word "abc", taking into account lowercase and uppercase letters.

--- 

### Parse string

Write a program that accepts a string as a command-line argument. The program should extract the words from the string
and create a new string, which consists unique words sorted alphabetically. Words in the input string can be separated
by the following characters `',' '' ';' '.' ':'.`.

--- 

### Extensive `qsort()`

Create an array of 10 strings, each 15 characters long. Fill it with random letters. Use `qsort()` to sort each row of
the array, and then sort the entire array(wrapper). Sorting rules: the uppercase letter is before the lowercase letter,
i.e. string: "hhjklmnnwuuuuaa" after sorting it looks like this "aahhjklmnnuuuuw".

--- 