# nqueens
Single-threaded and multi-threaded C implementations of the n queens problem.
The n-queens problem can be seen [here](https://en.wikipedia.org/wiki/Eight_queens_puzzle)
> The eight queens puzzle is the problem of placing eight chess queens on an 8×8 chessboard so that no two queens threaten each other; thus, a solution requires that no two queens share the same row, column, or diagonal. The eight queens puzzle is an example of the more general n queens problem of placing n non-attacking queens on an n×n chessboard, for which solutions exist for all natural numbers n with the exception of n = 2 and n = 3.[1]

# Building and Usage
To build, run `make`. 

Pass a single value in arg1 for num queens. 
 
## Single threaded
To run single threaded instance
```bash
./single-thread <numqueens>
```

## Examples 
Ran on 2021 Apple MacBook Pro w/ M1 Max CPU: 
```bash
% ./single-thread 12
Single thread
First: 0  Solutions: 500
First: 1  Solutions: 806
First: 2  Solutions: 1165
First: 3  Solutions: 1359
First: 4  Solutions: 1631
First: 5  Solutions: 1639
First: 6  Solutions: 1639
First: 7  Solutions: 1631
First: 8  Solutions: 1359
First: 9  Solutions: 1165
First: 10  Solutions: 806
First: 11  Solutions: 500
Total solutions: 14200
Elapsed time: 20.662184
```
```bash
% ./multi-thread 12
Multi threaded
First: 8  Solutions: 1359
First: 3  Solutions: 1359
First: 5  Solutions: 1639
First: 6  Solutions: 1639
First: 7  Solutions: 1631
First: 4  Solutions: 1631
First: 11  Solutions: 500
First: 9  Solutions: 1165
First: 2  Solutions: 1165
First: 10  Solutions: 806
First: 1  Solutions: 806
First: 0  Solutions: 500
Total solutions: 14200
Elapsed time: 2.514626
```
