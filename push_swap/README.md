*This project has been created as part of the 42 curriculum by diatisin and mdecarli*

## Description
Push_swap is an algorithmic project at 42 where the goal is to sort a stack of integers using a secondary stack and a restricted set of allowed operations, minimizing the total number of moves.

This implementation features an Adaptive Sorting Strategy that computes the input stack's disorder metrics to dynamically select the most efficient algorithm.

Allowed Operations
sa / sb / ss: Swap the first two elements at the top of stack A, stack B, or both.

pa / pb: Push the top element from stack B to A, or from A to B.

ra / rb / rr: Shift up all elements of a stack by 1. The first element becomes the last.

rra / rrb / rrr: Shift down all elements of a stack by 1. The last element becomes the first.

## Algorithmic Architecture

compute_disorder_ps measures the ratio of inverted pairs (0.0 = sorted, 1.0 = fully reversed) and selects the algorithm at runtime:
```text
              ┌─────────────────────────┐
              │   compute_disorder_ps   │
              └────────────┬────────────┘
                           │
     ┌─────────────────────┼─────────────────────┐
     ▼                     ▼                     ▼
Disorder < 0.2      0.2 ≤ Disorder < 0.5   Disorder ≥ 0.5
┌─────────────────┐ ┌─────────────────┐ ┌─────────────────┐
│   Simple Sort   │ │   Chunk Sort    │ │   Quick Sort    │
│     O(n²)       │ │    O(n√n)       │ │   O(n log n)    │
└─────────────────┘ └─────────────────┘ └─────────────────┘
```

Simple Sort O(n²): Fixed move sequences for N≤3; selection-style for near-sorted inputs.

Chunk Sort O(n√n): Normalizes indices, pushes elements to B in N/5 chunks (N/11 for N>100), pre-sorting by proximity, then pulls back to A by always targeting the max-index element.

Quick Sort O(n log n): Recursive dual-stack quicksort. Pivot = midpoint between min and max of current block. Elements below pivot go to B, above stay in A; recurses on both halves. Base cases: N≤3 use sort_small_a.

## Performance Benchmark
Input size	Operations	Performance
```
100 numbers	~820 ops	Good (< 1500)
500 numbers	~6600 ops	Good (< 8000)
```

## Instructions
bash
```
make
```
Pass a list of space-separated integers:

bash
./push_swap 42 -10 5 0 12 -2 8 3

Or a single string:

bash
./push_swap "42 -10 5 0 12 -2 8 3"

Strategy Selector (optional flag)  
bash  
```
./push_swap --simple 5 3 1 4 2     # Force O(n²) algorithm  
./push_swap --medium 5 3 1 4 2     # Force O(n√n) algorithm  
./push_swap --complex 5 3 1 4 2    # Force O(n log n) algorithm  
./push_swap --adaptive 5 3 1 4 2   # Adaptive (default)  
./push_swap --bench 5 3 1 4 2      # Show benchmark metrics on stderr  
```

Error Handling

Invalid inputs (non-numeric, overflow, duplicates) output Error to stderr:  

bash  
```
./push_swap 42 5 42      # Error: duplicates  
./push_swap 42 abc 3     # Error: non-integer  
./push_swap 2147483648   # Error: overflow  
```

## Cleaning Up
bash
```
make clean    # Remove object files
make fclean   # Remove object files and binary
make re       # Full recompilation
```

## Contributors
diatisin: chunk sort, quick sort, disorder, parser, utils, benchmode, makefile  
mdecarli: simple sort, quick sort, allowed operations, disorder, utils, readme

## Resources
- Sorting Algoritms: https://en.wikipedia.org/wiki/Sorting_algorithm
- Big O: https://en.wikipedia.org/wiki/Big_O_notation
- Claude.ai (claude.ai): used as a learning tool to understand new concepts.
  No code was generated directly by AI.