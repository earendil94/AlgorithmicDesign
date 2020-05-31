#include "insertion_sort.h"

#define CONST_ELEM(index) (const void*) (A+((index)*elem_size))
#define ELEM(index) (A+((index)*elem_size))

void insertion_sort(void *A, const unsigned int n, 
                    const size_t elem_size, 
                    total_order leq)
{
    int t;

    for(unsigned int i = 1; i < n; ++i){

        t = i;

        while(t > 0 && leq(CONST_ELEM(t),CONST_ELEM(t-1))){
            swap(ELEM(t), ELEM(t-1), elem_size);
            --t;
        }
    }
}