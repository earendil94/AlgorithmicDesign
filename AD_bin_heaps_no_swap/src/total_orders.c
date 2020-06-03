#include <stdlib.h>
#include <stdio.h>

int leq_float(const void *a, const void *b)
{
  return *((float*)a)<=*((float*)b);
}

int leq_int(const void *a, const void *b)
{
  return *((int*)a)<=*((int*)b);
}

int geq_int(const void *a, const void *b)
{
  int a_t = *((int*)a);
  int b_t = *((int*)b);
  return a_t >= b_t;
}