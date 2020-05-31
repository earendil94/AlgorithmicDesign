#ifndef __MATRIX__
#include <stdlib.h>

void general_naive_matrix_multiplication(float **C, float const *const *const A,
                                float const *const *const B,
                                const size_t A_rows, const size_t A_cols,
                                const size_t B_rows, const size_t B_cols);
void naive_matrix_multiplication(float **C, float const *const *const A,
                                float const *const *const B,
                                const size_t n) ;
int same_matrix(float const *const *const A, float const *const *const B,
                const size_t rows, const size_t cols);
float **allocate_matrix(const size_t rows, const size_t cols);
void deallocate_matrix(float **A, const size_t rows);
float **allocate_random_matrix(const size_t rows, const size_t cols);
float **make_it_square(const float *const *const A, const size_t old_rows, const size_t old_cols, const size_t n);
float **make_it_even(const float *const *const A, const size_t row_offset, const size_t col_offset, const size_t n);
size_t max(size_t a, size_t b, size_t c);
size_t min(size_t a, size_t b, size_t c);
float **enlarge_your_matrix(const float *const *const A, const size_t a_old_rows, 
                            const size_t a_old_cols, const size_t a_new_rows, const size_t a_new_cols );

#endif //__MATRIX__
