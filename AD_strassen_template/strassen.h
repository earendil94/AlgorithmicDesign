#ifndef __STRASSEN__

void strassen_matrix_multiplication(float **C, float const *const *const A,
                                    float const *const *const B, size_t n);

void gen_strassen_matrix_multiplication(float **C, float const *const *const A, float const *const *const B,
                                    size_t a_rows, size_t a_cols, size_t b_rows, size_t b_cols);

void optimized_strassen_matrix_multiplication(float **C, float const *const *const A,
                                    float const *const *const B, size_t n);

void naive_aux(float **C, float const *const *const A,
               float const *const * const B,
               const size_t C_f_row, const size_t C_f_col,
               const size_t A_f_row, const size_t A_f_col,
               const size_t B_f_row, const size_t B_f_col,
               const size_t A_row_dim, const size_t A_col_dim, const size_t B_col_dim);

void optimized_strassen_aux(float **C, float const *const *const A,
                  float const *const * const B,
                  const size_t C_f_row, const size_t C_f_col,
                  const size_t A_f_row, const size_t A_f_col,
                  const size_t B_f_row, const size_t B_f_col,
                  const size_t n);

void strassen_aux(float **C, float const *const *const A,
                  float const *const * const B,
                  const size_t C_f_row, const size_t C_f_col,
                  const size_t A_f_row, const size_t A_f_col,
                  const size_t B_f_row, const size_t B_f_col,
                  const size_t n);
#endif 
