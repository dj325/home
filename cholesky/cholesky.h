static double* cholesky(double* A, int n);
static double* initialise_L(int n);
double* fill_L(double* A, double* L, int n);
void print_matrix(double* A, int n);

static double* cholesky(double* A, int n){
  double* L = initialise_L(n);
  L = fill_L(A, L, n);

  return L;
}

void print_matrix(double *A, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%2.5f ", A[i * n + j]);
        printf("\n");
    }
}

static double* initialise_L(int n){
  double* L = (double*)calloc(n*n, sizeof(double));
  return L;
}

double* fill_L(double* A, double* L, int n){
  for(int i=0; i<n; i++){
    for(int j=0; j<i+1; j++){
      double sum = 0;
      for(int k=0; k<j; k++){
        sum += L[i*n + k] * L[j*n + k];
      }
      if(i==j){
        L[i*n + j] = sqrt(A[i*n + i] -sum);
      }
      if(i>j){
        L[i*n + j] = (1.0/L[j*n + j]) * (A[i*n + j] - sum);
      }
    }
  }
  return L;
}
