###TASK:

In the game mag-mino is used blocks that have the shape of 
rectangles, on both ends of which is located get the number 
of stitches from 0 to 9. The number of stitches is different
on each piece with two ends. In a set of 90 all combinations 
of meshes occur in the game blocks and each combination occurs
exactly once. Please write a function that, for a given set 
of N blocks, determines the longest string that can be 
constructed from them. For example, for a set of 8 blocks:
[2/8] [0/1] [2/3] [3/6] [2/6] [2/9] [3/4] [6/7] the longest 
string that can be arranged is 5 in length and has the form
: [8/2] [2/3] [3/6] [6/2] [2/9]

Data describing the set:

```C
const int N= …
struct klocek {
 int a;
 int b; // b>a
};
klocek zestaw[N];
```

The function should be passed a set of blocks, the function
should return the largest length of the string that you can 
from this build kit. Tip: when can you build a string from 
a set of blocks?