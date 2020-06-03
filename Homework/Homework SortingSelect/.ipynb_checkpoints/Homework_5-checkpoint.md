### 1.

In order to generalize the Select Algorithm presented in class to deal with repeated values, let's understand first why such generalization is needed, and why we cannot just apply the algorithm that we've already seen. Suppose to have an array made of elements with the same value k. Then, following the split into chunks we would face a situation in which we need to define an upper bound for the number of elements on which to reapply the algorithm recursively. If we just divide the array into a subarray of elements $ <= M$, where $M$ is the median of medians and one subarray of elements $> M$, then our first subarray will contain all the elements! 

A possible solution is to instead divide the array in three subarrays, one such that all the elements are smaller than $M$, one in which they are equal to $M$ and the last one in which they are greater than $M$. In this case we don't need to make a recursive call on the algorithm if the index to search belongs to the subarray of elements equal to $M$: we can just return M! Therefore, in order to find the worst possible solution for the complexity of the algorithm, the subarray of elements equal to $M$ needs to be as small as possible and this gets us back to the case analysed on the first algorithm, for which we know that the overall complexity is $O(n)$.

### 4. 
(Ex. 9.3-5 in [1]) Suppose that you have a \black-box" worst-case linear-
time subroutine to get the position in A of the value that would be in
position $n\2$ if A was sorted. Give a simple, linear-time algorithm that
solves the selection problem for an arbitrary position i.

#### Solution
Given this black-box algorithm, it means that we are able to find the median of the array A in linear time with respect to n. Then, we could partition the array based on the value of the median as we have described in point 1 and reapply the algorithm on the part of the array to which i belongs; we have already seen that this procedure takes time $O(n)$

### 5.

### 1) Recursion tree method

The recursive equation to solve is $T_1(n) = 2 T_1 \left(\frac{n}{2} \right ) + O(n)$.

From here on we will use an iterative method which uses the same methodology seen for the recursion tree, only without a graphical representation

Our recursive equation becomes 
$$ T_1(n) = 2 \cdot \left [ 2 T_1(\frac{n}{4}) + O(\frac{n}{2}) \right ] + O(n) = \cdots = \sum_{i=0} \left [ 2^{i+1} T(1) + 2^{i} O(\frac{n}{2^i}) \right ] = \sum_{i=0} \left [ 2^{i+1} T(1) + O(n) \right ] $$

What is the upper bound of our sum? It is the $i^*$ such that 
$$
\frac{n}{2^{i^*}} = 1 \rightarrow i^* = log_2 n
$$

Then, knowing that T(1) = 1, we have 
$$
\sum_{i=0}^{log_2 n} \left [ 2^{i+1} + O(n) \right ] = 2 (2^{log_2 n + 1} - 1) + log_2 n \cdot O(n) = 2( 2n - 1) + O(n log_2 n) = O(n log_2 n + 4n - 2) = O(n log_2 n)
$$

### 1) Substitution method

Let's suppose $T_1(n) \leq k \cdot n \cdot log_2 n + \alpha n$ and let's take as a representative for O(n) the function $\beta n$.

Base case: $T_1(1) = 1 \leq \alpha \rightarrow \alpha \geq 1$

Suppose now that our supposition is valid up until $\frac{n}{2}$ and let's prove it for $n$.

$$
T_1(n) = 2 T_1 \left(\frac{n}{2} \right ) + O(n) 
\leq \left [ 2 \cdot k \cdot \frac{n}{2} \cdot log_2 \frac{n}{2} + \alpha \frac{n}{2} \right ]+ \beta n \leq \\
k n \cdot (log_2 n - 1) + (\alpha + \beta) n \leq \\  
k n \cdot log_2 n + (\alpha + \beta - k) n
$$

Then for 
$$
(\alpha + \beta - k) \leq \alpha \\
k  \geq \beta
$$

### 2) Recursion tree method



### 2) Substitution method

Let's choose $ cn \in O(n) $ and $ 1 \in \Theta(1)$ as representatives for our classes.

2) Assume that $ \forall m < n \; T_2(m) \leq cm $ and prove that $T_2(n) \leq cn $

Ok, so let's try for our specific case in which $$ T_2(n) = T_2  \left \lceil{\frac{n}{2}} \right \rceil + T_2  \left \lfloor{\frac{n}{2} } \right \rfloor  + 1 $$

Remember that we assumed that $T_2(m) \leq cm \:\: \forall m < n$

Then $$ T_2(n) \leq c \left \lceil{\frac{n}{2}} \right \rceil + c \left \lfloor{\frac{n}{2}} \right \rfloor + 1 \leq c \cdot n + 1 $$

But this is not enough! Since we have a $+1$ in the last line, hence it doesn't prove that $T_2(n) \in O(n) $

The problem is that we selected the wrong representative for $O(n)$!
Let's try with another one. Let's take $cn - d$ as a representative.

Our assumption becomes

Then $$ T_2(n) \leq c  \left \lceil{\frac{n}{2}} \right \rceil - d + c  \left \lfloor{\frac{n}{2}} \right \rfloor -d + 1 \leq c \cdot n -2d + 1 $$

Taking $ d \geq 1 $ we proved our assumption.

We can also prove that $T_2(n) \in \Omega(n)$ by substitution.

Then let's prove $$ T_2(n) \geq T_2  \left \lceil{\frac{n}{2}} \right \rceil + T_2 \left \lfloor{\frac{n}{2}} \right \rfloor + 1 $$

This, under our assumption is $$ T_2(n) \geq c  \left \lceil{\frac{n}{2}} \right \rceil + c \left \lfloor{\frac{n}{2}} \right \rfloor + 1  \geq cn + 1 \geq c \cdot n $$

#### Another equation

$$ T(n) = T \left( \frac{1}{5} n \right) + T \left( \frac{3}{4} n \right) + \Theta(n) $$

The tree is totally unbalanced. We can generalize the tree putting $\alpha = \frac{1}{5}; \:\: \beta = \frac{3}{4} $ in this case

On the $i_{th}$ level all the nodes contain $ \alpha^j,  \beta^{i-j}$ moves on left and right branch respectively.

Then, at $i_{th}$ level we have the complexity $$ \sum_{j=0}^i {j \choose i} \alpha^j \cdot \beta^{i-j} \cdot $$

In an infinite approximation we would have
$$ T(n) \leq \sum_{i=0}^\infty (\alpha + \beta)^i \cdot n $$

This is a geometric series and it is convergent if $\alpha + \beta < 1 $. In particular, it converges to $$ T(n) \leq \frac{1}{1- (\alpha + \beta) } \cdot n $$

This means that $T(n) \in O(n) $. He also proved that $T(n) \in \Theta(n)$ (just review at @1:30 more or less).