#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "cholesky.h"

int main(int argc, char* argv[]){
  int n = 3;
  double A[] = {4,12,-16,
                12,37,-43,
                -16,-43,98};
  double* L = cholesky(A, n);
  print_matrix(L, n);
  free(L);

  return 0;
}
