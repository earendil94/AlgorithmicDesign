## Binary Heaps: Homework 2

### 2

Consider the next algorithm:

    def Ex2 (A)
        D <- build (A)
        while not is_empty (D)
            extract_min (D)
        endwhile
    enddef
where A is an array. Compute the time-complexity of the algorithm when:
* build, is_empty $ \in \Theta(1)$, extract_min $\in \Theta(|D|)$;
* build $\in \Theta(|A|)$, is_empty $\in \Theta(1)$, extract_min $\in O(log n)$;

#### Solution

* 1) In the first case, build has complexity $\Theta(1)$ and it is outside a loop so we can asymptotically ignore it with respect to the second part of the algorithm. The while loop checks a condition in time $\Theta(1)$ each time it runs, and a single execution of extract_min takes time $\Theta(|D|)$ so this is where we have to focus. How many times does the while loop get performed? Based on a sensible interpretation of the effect of the routines, the data structure (probably the heap) loses an element (its minimum), at each iteration of the while loop, up until it's completely empty and the function ends. Therefore the complexity can be summarized as $\sum_{i=1}^{|D|} \Theta(i) \approx \Theta(|D|^2)$
* 2) (Here we will be supposing n = |D|) In the second scenario instead we need to take into consideration also the coroutine build. Our complexity now will be 
$$\Theta(|A|) + \sum_{i=0}^{|D|} log(i) = \\
\Theta(A) + log(\prod_{i=0}^{|D|} i ) = \\
\Theta(|A|) + log(|D|!) \approx \Theta(|A|) + n\; log(n)
$$ 
where the last passage was obtained by the usage of Stirling Approximation