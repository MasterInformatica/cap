#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <assert.h>
#include "omp.h"

#include "cholesky.h"

double* cholesky_blocked(const int n, double* A)
{
    double *L = (double*)calloc(n * n, sizeof(double));
    if (L == NULL)
        exit(EXIT_FAILURE);
 
    for (int i = 0; i < n; i++)
        for (int j = 0; j < (i+1); j++) {
            double s = 0;
            for (int k = 0; k < j; k++)
                s += L[i * n + k] * L[j * n + k];
            L[i * n + j] = (i == j) ?
                           sqrt(A[i * n + i] - s) :
                           (1.0 / L[j * n + j] * (A[i * n + j] - s));
        }
 
    return L;
}



int main(int argc, char* argv[])
{
   char *result[3] = {"n/a","sucessful","UNSUCCESSFUL"};
   const double eps = 1e-9;

   if ( argc < 2) {
      printf( "TAM MATRIX\n" );
      exit( -1 );
   }

   const int  n = atoi(argv[1]); // matrix size

   // Allocate matrix
   double * const matrix = (double *) malloc(n * n * sizeof(double));
   assert(matrix != NULL);


#ifdef VERBOSE
   printf ("Executing ...\n");
#endif
   
   const float t1 = get_time();
   double* C = cholesky_blocked(n, (double* )matrix);
   const float t2 = get_time() - t1;



   float time = t2;
   float gflops = (((1.0 / 3.0) * n * n * n) / ((time) * 1.0e+9));

   // Print results
#ifdef VERBOSE
   printf( "============ %s ============\n", argv[0] );
   printf( "  matrix size:          %dx%d\n", n, n);
   printf( "  time (s):             %f\n", time);
   printf( "  performance (gflops): %f\n", gflops);
   printf( "==========================================\n" );
#else
   printf( "%s\nmatrix_size: %dx%d\ntime:%f\nperformance:%f\n", argv[0], n, n, time, gflops);
#endif

   // Free matrix
   free(matrix);
   free(C);

   return 0;
}

