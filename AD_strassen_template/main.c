#include <stdio.h>

#include "test.h"
#include "matrix.h"
#include "strassen.h"

int main() {
  size_t n = 1 << 10;

  float **A = allocate_random_matrix(n, n);
  float **B = allocate_random_matrix(n, n);
  float **C0 = allocate_matrix(n, n);
  float **C1 = allocate_matrix(n, n);


  printf("n\tStrassen's Alg.\tOptimized Strassen \tNaive Alg.\tSame result\n");
  for (size_t j = 1; j <= n; j *= 2) {

    // printf("%ld\t", j);
    // fflush(stdout);

    printf("%lf\t", test(strassen_matrix_multiplication, C1, A, B, j));
    fflush(stdout);
    printf("%lf\t", test(optimized_strassen_matrix_multiplication, C0, A, B, j));
    fflush(stdout);
    printf("%lf\t", test(naive_matrix_multiplication, C0, A, B, j));
    fflush(stdout);
  
    printf("%d\n", same_matrix((float const *const *const)C0,
                               (float const *const *const)C1, j, j));
  }

  deallocate_matrix(A, n);
  deallocate_matrix(B, n);
  deallocate_matrix(C0, n);
  deallocate_matrix(C1, n);

  size_t r1 = 200;
  size_t c1 = 110;
  size_t r2 = 110;
  size_t c2 = 400;

  A = allocate_random_matrix(r1, c1);
  B = allocate_random_matrix(r2, c2);

  C0 = allocate_matrix(r1, c2);
  C1 = allocate_matrix(r1, c2);
  printf("n\tOptimized Strassen \tNaive Alg.\tSame result\n");
  printf("Odd matrix test\t");

  printf("%lf\t", general_test(gen_strassen_matrix_multiplication, C1, A, B, r1, c1, r2, c2));
  printf("%lf\t", general_test(general_naive_matrix_multiplication, C0, A, B, r1, c1, r2, c2));

  printf("%d\n", same_matrix((float const *const *const)C0,
                      (float const *const *const)C1, r1, c2));

  deallocate_matrix(A, r1);
  deallocate_matrix(B, r2);
  deallocate_matrix(C0, r1);
  deallocate_matrix(C1, r1);


  return 0;
}
