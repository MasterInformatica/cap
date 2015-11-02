#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <assert.h>
#include "omp.h"

#include "cholesky.h"

void omp_potrf(double * const A, int ts, int ld)
{
   static int INFO;
   static const char L = 'L';
   dpotrf_(&L, &ts, A, &ld, &INFO);
}


double *cholesky_blocked(const int n, double* A)
{
  omp_potrf(A, n, n);
  return A;
}


int main(int argc, char* argv[])
{
   char *result[3] = {"n/a","sucessful","UNSUCCESSFUL"};


   if ( argc < 2) {
      printf( "<usage>: cholesky matrix_size\n" );
      exit( -1 );
   }
   const int  n = atoi(argv[1]); // matrix size

   // Allocate matrix
   double *  matrix = (double *) malloc(n * n * sizeof(double));
   assert(matrix != NULL);

   // Init matrix
   initialize_matrix(n, n, matrix);

#ifdef VERBOSE
   printf ("Executing ...\n");
#endif

   const float t1 = get_time();
   matrix = cholesky_blocked(n, (double *)matrix);
   const float t2 = get_time() - t1;

   float time = t2;
   float gflops = (((1.0 / 3.0) * n * n * n) / ((time) * 1.0e+9));

   // Print results
#ifdef VERBOSE
   printf( "============ CHOLESKY RESULTS ============\n" );
   printf( "  matrix size:          %dx%d\n", n, n);
   printf( "  time (s):             %f\n", time);
   printf( "  performance (gflops): %f\n", gflops);
   printf( "==========================================\n" );
#else
   //   printf( "test:%s-%d-%d:threads:%2d:result:%s:gflops:%f\n", argv[0], n, ts, omp_get_num_threads(), result[check], gflops );
#endif

   // Free matrix
   free(matrix);

   return 0;
}

