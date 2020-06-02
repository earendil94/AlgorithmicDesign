#include "quick_sort.h"
#include "select.h"
#include "selection_sort.h"
#include <time.h>
#include <stdlib.h>

#define CONST_ELEM(index) (const void*) (A+((index)*elem_size))
#define ELEM(index) (A+((index)*elem_size))

void quick_sort(void *A, const unsigned int n, 
                const size_t elem_size, 
                total_order leq)
{
    quick_sort_aux(A, n, elem_size, leq, 0, n-1);
}

void naive_quick_sort_aux(void *A, const unsigned int n, const size_t elem_size, total_order leq, const int l, const int r){
    
    if(l < r){
        int p = partition(A, n, elem_size, leq, l, r);
        quick_sort_aux(A, n, elem_size, leq, l, p-1);
        quick_sort_aux(A, n, elem_size, leq, p+1, r);
    }
}

void quick_sort_aux(void *A, const unsigned int n, const size_t elem_size, total_order leq, const int l, const int r){
    
    // if (r-l <= 10){
    //     selectionSortAux(A, elem_size, leq, l, r);
    //     return;
    // }   

    if(l < r){
        int* p = yathreeWayPartition(A, elem_size, leq, l, r, l);
        quick_sort_aux(A, n, elem_size, leq, l, p[0]-1);
        quick_sort_aux(A, n, elem_size, leq, p[1]+1, r);
    }
}


int partition(void *A, const unsigned int n, const size_t elem_size, total_order leq, const int l, const int r){
    // //Casually select the pivot: I am commenting this for now //TODO: this greaty improves our performances, I think we should put it
    //anyway and comment accordingly.
    // srand(time(NULL)); 
    // int p = rand()%(r-l)+l;

    int p = l;

    //1. Swap the pivot and the first element of the array
    swap(ELEM(l), ELEM(p), elem_size);

    //2. If A[i] > p, swap A[i] and A[j] and decrease j else increase i
    int i = l+1;
    int j = r;

    while( i <= j){
        if(leq(CONST_ELEM(l), CONST_ELEM(i))){
            swap(ELEM(i), ELEM(j), elem_size);
            --j;
        }
        else{
            ++i;
        } 
    }

    swap(ELEM(j), ELEM(l), elem_size);

    return j;
}

int * yathreeWayPartition(void *A, const size_t elem_size, total_order leq, const unsigned int l, const unsigned int r, const unsigned int p){

    //1. Swap the pivot and the first element of the array
    swap(ELEM(l), ELEM(p), elem_size);

    //2. If A[i] > p, swap A[i] and A[j] and decrease j else increase i
    int i = l+1;
    int j = r;
    int eq = l+1;

    while( i <= j){

        if(leq(CONST_ELEM(l), CONST_ELEM(i)) && leq(CONST_ELEM(i), CONST_ELEM(l))){
            swap(ELEM(i), ELEM(eq), elem_size);
            ++eq;
            ++i;
        } else if(leq(CONST_ELEM(l), CONST_ELEM(i))){
            swap(ELEM(i), ELEM(j), elem_size);
            --j;
        } else{
            ++i;
        } 
    }

    for(size_t t = 0; t <= (eq-l-1); ++t)    
        swap(ELEM(j-t), ELEM(l+t), elem_size);

    int *pivots = malloc(2*sizeof(int));
    pivots[0] = j - (eq-l-1);
    pivots[1] = j;

    return pivots;
}