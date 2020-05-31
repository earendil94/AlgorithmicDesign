#include "bubble_sort.h"

#define CONST_ELEM(index) (const void*) (A+((index)*elem_size))
#define ELEM(index) (A+((index)*elem_size))

void bubble_sort(void *A, const unsigned int n, 
                 const size_t elem_size, 
                 total_order leq)
{

    int fl;

    for(size_t i = n; i > 0; --i){

        fl = 0;

        for(size_t k = 0; k < i-1; ++k){
            if(leq(CONST_ELEM(k+1), CONST_ELEM(k))){
                swap(ELEM(k), ELEM(k+1), elem_size);
                fl = 1;
            }
        }

        if(fl == 0)
            break;
    }
}