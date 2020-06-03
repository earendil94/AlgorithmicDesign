#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

#define MIN(rows,cols) (rows < cols)

//This algorithm computes a matrix matrix multiplication by following the definition and is extended to rectangular matrices
void general_naive_matrix_multiplication(float **C, float const *const *const A,
                                float const *const *const B,
                                const size_t A_rows, const size_t A_cols,
                                const size_t B_rows, const size_t B_cols) 
{
  for (size_t y = 0; y < A_rows; y++) {
    for (size_t x = 0; x < B_cols; x++) {
      float value = 0.0;
      for (size_t z = 0; z < A_cols; z++) {
        value += A[y][z]*B[z][x];
      }

      C[y][x] = value;
    }
  }
}

void naive_matrix_multiplication(float **C, float const *const *const A,
                                float const *const *const B,
                                const size_t n) 
{
  for (size_t y = 0; y < n; y++) {
    for (size_t x = 0; x < n; x++) {
      float value = 0.0;
      for (size_t z = 0; z < n; z++) {
        value += A[y][z]*B[z][x];
      }

      C[y][x] = value;
    }
  }
}

int same_matrix(float const *const *const A, float const *const *const B,
                const size_t rows, const size_t cols) {
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols; j++) {
      if (A[i][j] != B[i][j]) {
        return 0;
      }
    }
  }

  return 1;
}

float **allocate_matrix(const size_t rows, const size_t cols) {
  float **M = (float **)malloc(sizeof(float *) * rows);

  for (size_t i = 0; i < rows; i++) {
    M[i] = (float *)malloc(sizeof(float) * cols);
  }

  return M;
}

void deallocate_matrix(float **A, const size_t rows) {
  for (size_t i = 0; i < rows; i++) {
    free(A[i]);
  }

  free(A);
}

float **allocate_random_matrix(const size_t rows, const size_t cols) {
  
  float **A = allocate_matrix(rows, cols);
  
  srand(10);
  for (size_t i = 0; i < rows; i++) {
    for (size_t j = 0; j < cols; j++) {
      A[i][j] = (rand() - RAND_MAX / 2) % 5;
    }
  }

  return A;
}

float **make_it_square(const float *const *const A, const size_t old_rows, const size_t old_cols, const size_t n)
{

  float **M;
  M = allocate_matrix(n,n);

  for(size_t i = 0; i < old_rows; ++i){
    for(size_t j = 0; j < old_cols; ++j)
      M[i][j] = A[i][j];   
    for(size_t j = old_cols; j < n; ++j)
      M[i][j] = 0;
  
  }
      
  for(size_t i = old_rows; i < n; ++i)
    for(size_t j = 0; j < n; ++j)
      M[i][j] = 0;   
  
  return M;

}

float **make_it_even(const float *const *const A, const size_t row_offset, const size_t col_offset, const size_t n)
{

  float **M;
  M = allocate_matrix(n+1,n+1);

  for(size_t i = 0; i < n; ++i){
    for(size_t j = 0; j < n; ++j)
      M[i][j] = A[row_offset+i][col_offset + j];   
    
    M[i][n] = 0;
  
  }
      
  for(size_t j = 0; j < n+1; ++j)
    M[n][j] = 0;   

  return M;

}

float **enlarge_your_matrix(const float *const *const A, const size_t a_old_rows, 
                            const size_t a_old_cols, const size_t a_new_rows, const size_t a_new_cols )
{

  float **M;
  M = allocate_matrix(a_new_rows, a_new_cols);

  for(size_t i = 0; i < a_old_rows; ++i){
    for(size_t j = 0; j < a_old_cols; ++j)
      M[i][j] = A[i][j];   

    for(size_t j = a_old_cols; j < a_new_cols; ++j)
      M[i][j] = 0; 
  }
  
  for(size_t i = a_old_rows; i < a_new_rows; ++i){
    for(size_t j = 0; j < a_new_cols; ++j)
      M[i][j] = 0;   
  }

  return M;

}

size_t max(size_t a, size_t b, size_t c){

  size_t tmp_max = a;
  if( b > tmp_max)
    tmp_max = b;
  
  if( c > tmp_max)
    tmp_max = c;
  
  return tmp_max;

}

size_t min(size_t a, size_t b, size_t c){

  size_t tmp_min = a;
  if( b < tmp_min)
    tmp_min = b;
  
  if( c < tmp_min)
    tmp_min = c;
  
  return tmp_min;

}