#include <stdio.h>

#include "test.h"
#include "matrix.h"
#include "strassen.h"

int main(int argc, char *argv[]) {
 
    size_t r1 = 200;
    size_t c1 = 400;
    size_t r2 = c1;
    size_t c2 = 300;

    float **A = allocate_random_matrix(r1, c1);
    float **B = allocate_random_matrix(r2, c2);

    size_t n = max(r1,c1,c2);

    float **C0 = allocate_matrix(n, n);
    float **C1 = allocate_matrix(n, n);

    printf("%lf\t", general_test(gen_strassen_matrix_multiplication, C1, A, B, r1, c1, r2, c2));
    printf("%lf\t", general_test(general_naive_matrix_multiplication, C0, A, B, r1, c1, r2, c2));

    deallocate_matrix(A, n);
    deallocate_matrix(B, n);
    deallocate_matrix(C0, n);
    deallocate_matrix(C1, n);


    return 0;
}
