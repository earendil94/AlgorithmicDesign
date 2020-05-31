#ifndef __TEST__

//Fix test
double test(void (*f)(float **,
	                  float const *const *const,
	                  float const *const *const,
	                  size_t), 
	        float **C, float** A, float **B, size_t n);
double general_test(void (*f)(float **,
	                  float const *const *const,
	                  float const *const *const,
	                  size_t, size_t, size_t, size_t),
	        			float **C, float** A, float **B, size_t A_rows, size_t A_cols, size_t B_rows, size_t B_cols);

#endif // __TEST__
