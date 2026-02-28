# Solution

Consider having some array. 
Let $M$ be the `mex` of this array. 

Let us find the smallest $x$ such that `count(x) != 1`. Here we can find 2 cases. 

## case 1: x is the mex
In this case, our array looks like [0, 1, ..., \x\\, ...]. 
After one operation, it looks like, 
[0, 1, ..., x] or [0, 1, ..., x, x, ...]
After 2 operations, it looks like 
[0, 1, ..., x+1, x+1, ...]
After 3 operations, it looks like 
[0, 1, ..., x, x, x, ...]
And endlessly cycles like this forever 
## case 2: x is not mex 
In this case, our array looks like, 
[0, 1, ..., x, ..., x, ...]
After 1 operation, our array looks like, 
[0, 1, ..., M, ..., M, ...]
and x is the new mex.
Which brings us to case 1. 

## finding the mex 
This is an $O(n)$ operation. But it must only be done once. Afterwards, the new mex can be calculated. 

## States 

State 1: Permutation (1, 2, 3, ..., n)
no more cycles 
State 2: No repeated element less than M.
Proceed to state 1 or state 3
State 3. repeated permutation, (1, 2, 3, ..., n, n, n)
This is a cyclical terminal state.
State 4: Repeated element x < M
Proceed to state 2 with M = x