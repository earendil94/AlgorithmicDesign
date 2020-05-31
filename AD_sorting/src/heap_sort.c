#include "heap_sort.h"
#include <stdio.h>

#define CONST_ELEM(index) (const void*) (A+((index)*elem_size))
#define ELEM(index) (A+((index)*elem_size))

void heap_sort(void *A, const unsigned int n, 
               const size_t elem_size, 
               total_order leq)
{

    binheap_type* H = build_heap(A,n,n,elem_size,leq);


    for( size_t i = n-1; i > 0 ; --i){    
        extract_min(H);//extract min should already place the minimum at the last element of the array
    }

    //The array now is ordered from the highest to the lowest value, so we need to revert it
    for(size_t i = 0; i < n/2; ++i)
        swap(ELEM(i), ELEM(n-i-1), elem_size);
        
    free(H);

}

