###TASK:

The data is a declaration representing a list with mag-mino blocks (see task 2).

```C
struct domino {
    int a;
    int b;
    domino *next;
};
```

The list contains a set of blocks that can be arranged in a sequence.
Unfortunately, the blocks are mixed up. Please write function, which sets
the blocks in the list in a sequence. Note: the orientation of the blocks 
in the list is correct.

```Text
For example, a list: [2/9] [3/6] [8/2] [2/3] [6/2]
convert to list: [8/2] [2/3] [3/6] [6/2] [2/9]
```
