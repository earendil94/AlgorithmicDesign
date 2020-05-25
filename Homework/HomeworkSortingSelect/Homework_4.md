

### 3. 
Argue about the following statement and answer the questions

(a) HEAP SORT on a array A whose length is n takes time $O(n)$.

(b) HEAP SORT on a array A whose length is n takes time $\Omega(n)$.

(c) What is the worst case complexity for HEAP SORT?

(d) QUICK SORT on a array A whose length is n takes time O($n^3$).

(e) What is the complexity of QUICK SORT?

(f) BUBBLE SORT on a array A whose length is n takes time O(n).

(g) What is the complexity of BUBBLE SORT?

#### Solution

a) This is false since we have no information whether the array is sorted or not. We know that every sorting method based on comparison, \textbf{in the worst case}, has a complexity of order $\Omega(n \cdot log n)$, i.e. it is not possible to perform a sorting (in the worst case scenario) using comparisons in a complexity asymptotically better than $(n \cdot log n)$

b) This is actually true for Heap Sort, since in the best case scenario (already sorted array) our algorithm will perform exactly n steps (n extraction of the minimum which require no call to heapify to restore the heap property). Every other scenario will have a greater complexity thus being a function $g(n) \geq n$ hence $\Omega(n)$

c) The worst case scenario for heap sort is given by $O(n \cdot log n)$ since it would take $log(n)$ iteration for each extraction of the maximum, and this process needs to be repeated $n$ times (for a more mathematical precise description, refer to case 2 of exercise 2 of the second heap homework, which is exactly our algorithm for heapsort).

d) Technically is true, since the complexity of Quicksort is a function $g(n)$ such that $g(n) \leq k n^3$ for a certain $k \in R,\; \forall n \in R$. Nevertheless, this is a much larger upper bound than what is needed, in fact, Quicksort's worst case scenario (repeatedly bad pivot choice) takes time $O(n^2)$.

e) The complexity of Quicksort on an average case is $O(n \cdot log(n))$

f) This is false in the general case since Bubble sort can take up to $O(n^2)$ complexity to be performed.

g) The complexity of bubble sort is $O(n^2)$ on its worst case scenario (which corresponds to the array ordered in the opposite direction), since at each iteration we would need to make n comparisons, decreasing the array dimension by just 1. More precisely, we can model our complexity as $\sum_{i=0}^N i = O(n^2)$ where i is the number of comparisons to be made in order to sort the array.

### 4. 
Solve the following recursive equation:
$$ T(n) = 
\begin{cases} 
1 \:\:\:\:\: \:\:\:\:\: \:\:\:\:\:  \:\:\:\:\:  \:\:\:\:\:  \:\:\: if \: n = 32 \\
3T(\frac{n}{4}) + \Theta(n^{\frac{3}{2}}) \:\:\:\:\: otherwise \\
\end{cases}
$$

#### Solution

First of all let's consider $T(128) = 3T(32) + \Theta(128^\frac{3}{2}) = 3 O(1) + \Theta(128^\frac{3}{2})$.

This is the last step to be considered when iterating over $T(n)$. 

Performing the iteration we can see that 
$$ 
T(n) = \Theta(n^{\frac{3}{2}}) + 3 (\Theta((\frac{n}{4})^{\frac{3}{2}})) + ... = \sum_{i=0} 3^i \Theta \left( \left( \frac{n}{2^{2i}} \right)^\frac{3}{2} \right)
$$

The sup of our series is found by solving the equation $ \frac{n}{2^{2i}} = 128 \rightarrow i = \frac{log_2 n - 7}{2} $

Then our sum becomes
$$
T(n) = \sum_{i=0}^{i = \frac{log_2 n - 7}{2}} 3^i \Theta \left( \left( \frac{n}{2^{2i}} \right)^\frac{3}{2} \right) = \sum_{i=0}^{i = } \left( \frac{3}{8} \right)^i \Theta \left(n ^\frac{3}{2} \right) = \Theta \left(n ^\frac{3}{2} \right) \sum_{i=0}^{i = \frac{log_2 n - 7}{2}} \left( \frac{3}{8} \right)^i
$$ 

Since we have a geometric series with $q = \frac{3}{8}$ then
$$
T(n) = \Theta \left(n ^\frac{3}{2} \right) = \frac{( \frac{3}{8})^{\frac{log_2 n - 7}{2} + 1}}{ \frac{5}{8}} = \Theta \left(n ^\frac{3}{2} \right) \cdot n^{\frac{1}{log_{\frac{3}{8}} 2}} = \Theta \left(n ^{\frac{3}{2} + \frac{1}{log_{\frac{3}{8}} 2}}\right)
$$

