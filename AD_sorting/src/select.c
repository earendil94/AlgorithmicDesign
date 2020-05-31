#include "select.h"
#include "quick_sort.h"
#include "insertion_sort.h"
#include "swap.h"
#include <stdio.h>


#define CHUNK_SIZE 5
#define CONST_ELEM(index) (const void*) (A+((index)*elem_size))
#define ELEM(index) (A+((index)*elem_size))

unsigned int select_median(void *A, const unsigned int n,
                          const size_t elem_size, 
                          total_order leq)
{
    int alpha = select_aux(A, n/2, elem_size, leq, 0, n-1);
    printf("\n");
    printf("Our median is : %d\n", alpha);
    return 0;	
}

unsigned int naive_select_aux(void *A, const unsigned int i, const size_t elem_size, total_order leq, const unsigned int l, const unsigned int r){
    
    //Base case for efficiency reasons
    if (r-l <= 10){
        selectionSortAux(A, elem_size, leq, l, r);
        return i;
    }

    const unsigned int j = selectPivot(A, l, r, elem_size, leq);
    const unsigned int k = deterministicPivotPartition(A, elem_size, leq, l, r, j);


    if( i == k) //If we found our boy then we are done
        return k;
    
    if( i < k)
        return naive_select_aux(A, i, elem_size, leq, l, k);
    else
        return naive_select_aux(A, i, elem_size, leq, k+1, r);

}

unsigned int select_aux(void *A, const unsigned int i, const size_t elem_size, total_order leq, const unsigned int l, const unsigned int r){
    
    //Base case for efficiency reasons
    if (r-l <= 10){
        selectionSortAux(A, elem_size, leq, l, r);
        return i;
    }

    const unsigned int j = selectPivot(A, l, r, elem_size, leq);
    const int* k = threeWayPartition(A, elem_size, leq, l, r, j);

    //Generalized select recursive call
    if( i <= k[0]){
        return select_aux(A, i, elem_size, leq, l, k[0]);
    } else if (i > k[0] && i <= k[1]){
        return i;
    } else {
        return select_aux(A, i, elem_size, leq, k[1] + 1, r);
    }
    
}

//We'll call select to find the median
void quick_sort_select(void *A, const unsigned int n, 
                       const size_t elem_size, 
                       total_order leq)
{
    quick_sort_select_aux(A, n, elem_size, leq, 0, n-1);
}

void quick_sort_select_aux(void *A, const unsigned int n, const size_t elem_size, total_order leq, const unsigned int l, const unsigned int r){
    
    if (r-l <= 10){
        selectionSortAux(A, elem_size, leq, l, r);
        return;
    }   

    if(l < r){
        const unsigned int median = select_aux(A, (l+r)/2, elem_size, leq, l, r);
        const unsigned int p = deterministicPivotPartition(A, elem_size, leq, l, r, median);
        // printf("\np is: %d\n ", p);

        // for(size_t i = 0; i < n; ++i)
        // printf("%d ", *((int*)ELEM(i)));

        // printf("\n");
        quick_sort_select_aux(A, n, elem_size, leq, l, p);
        quick_sort_select_aux(A, n, elem_size, leq, p+1, r);
    }


}

int deterministicPivotPartition(void *A, const size_t elem_size, total_order leq, const unsigned int l, const unsigned int r, const unsigned int p){

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

int * threeWayPartition(void *A, const size_t elem_size, total_order leq, const unsigned int l, const unsigned int r, const unsigned int p){

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

    for(size_t t = 0; t < (eq-l-1); ++t)    
        swap(ELEM(j-t), ELEM(l+t), elem_size);

    int *pivots = malloc(2*sizeof(int));
    pivots[0] = j - (eq-l-1);
    pivots[1] = j;

    return pivots;
}


int selectPivot(void *A, unsigned const int l, unsigned const int r, const size_t elem_size, total_order leq){

    //Base case for efficiency reasons
    if (r-l <= 10){
        selectionSortAux(A, elem_size, leq, l, r);
        return (l+r)/2;
    }

    //const int chunks = (r-l)%CHUNK_SIZE == 0 ? (r-l)/CHUNK_SIZE : (r-l)/CHUNK_SIZE + 1;
    const int chunks = (r-l)/CHUNK_SIZE; //this way we are not counting the last one in case we can't divide by 5
    int cl, cr;


    // for(int c = 0;  c <= (chunks); ++c){
    //     cl = l + c*5;
    //     cr = cl+4;

    //     if(cr > r)
    //         cr = r;

    //     selectionSortAux(A,n,elem_size,leq,cl,cr);
    //     swap(ELEM(cl+(cr-cl)/2), ELEM(l+c), elem_size);
    // }

    for(int c = 0;  c <= (chunks-1); ++c){
        cl = l + c*5;
        cr = cl+4;

        selectionSortAux(A,elem_size,leq,cl,cr);
        swap(ELEM(cl+2), ELEM(l+c), elem_size);
    }

    

    return select_aux(A, l + chunks/2, elem_size, leq, l, l+chunks-1);

}

void selectionSortAux(void *A, const unsigned int elem_size, total_order leq, const unsigned int l, const unsigned int r){

    for(size_t i = r; i > l; --i){
        
        int max_index = l;

        for(size_t j = l+1; j <= i; ++j){

            if(leq(CONST_ELEM(max_index), CONST_ELEM(j))){
                max_index = j;
            }

        }

        swap(ELEM(i), ELEM(max_index), elem_size);
    }

}