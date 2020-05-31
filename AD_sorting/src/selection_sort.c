#include "selection_sort.h"

#define CONST_ELEM(index) (const void*) (A+(index*elem_size))
#define ELEM(index) (A+(index*elem_size))

void selection_sort(void *A, const unsigned int n, 
                    const size_t elem_size, 
                    total_order leq)
{

    int max; //Initialize the index with max value at the beginning of the array

    for(size_t i = n-1; i > 0; --i){
        
        max = 0;
        
        for(size_t k = 1; k <= i; ++k){
            if(leq(CONST_ELEM(max), CONST_ELEM(k)))
                max = k;
        }
        swap(ELEM(max),ELEM(i), elem_size);
    }

}