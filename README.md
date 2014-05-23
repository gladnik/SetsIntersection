SetsIntersection
================

Search common elements of two sets with **O(n)** comparisons.


**Sets Intersection:** Let **A** and **B** be the sets of size **n** with elements in {0,1,2,3,4,5,6,7,8,9}. Find elements that belong to both sets **A** and **B**.

**Goal:** Minimize the number of comparisons.


>**Primes product algorithm:**
 1. Replace elements of A and B with primes (e.g., i = i-th prime).
 2. Multiply all elements of set A.
 3. Divide obtained product with each element of set B. If remainder equals 0, that element belongs to both sets. Otherwise, that element does not belong to set A.
  
This algorithm requires **n** comparisons (remainder with 0).

[See how it works](http://ideone.com/gi9KnG "http://ideone.com/gi9KnG")
