
# Sorting Fixed-Length IDs Using Merge Sort and Quick Sort

## 1. Aim
To implement Merge Sort and Quick Sort in C and compare their performance using fixed-length IDs.

## 2. Input
324, 125, 456, 218, 102, 389, 275, 147

## 3. Algorithms Used
- Merge Sort
- Quick Sort

## 4. Programming Language
C

## 5. Expected Output
102, 125, 147, 218, 275, 324, 389, 456

## 6. Performance Analysis

| Feature | Merge Sort | Quick Sort |
|---|---|---|
| Average Time | O(n log n) | O(n log n) |
| Worst Time | O(n log n) | O(n^2) |
| Extra Space | O(n) | O(log n) average |
| Method | Divide and merge | Partition using pivot |

## 7. Conclusion
Both algorithms correctly sort the given IDs.
Merge Sort provides predictable worst-case performance,
while Quick Sort can be faster in practice and usually
requires less additional memory.

## 8. How to Run
1. Install a C compiler such as GCC.
2. Compile using: gcc sorting.c -o sorting
3. Run the executable.
