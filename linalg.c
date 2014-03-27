 /*********************************************************
 * Linear Algebra Module
 * Rev: 10/24/2013,  Juan C. Cockburn  (jcck@ieee.org)
 *********************************************************/

#include "linalg.h"

/* Allocate memory space for matrix, all at once */
MatElement **matrix_alloc(int nr, int nc) {
  int i;
  MatElement *ptr;
  MatElement **A;

  A = malloc( nr * sizeof(MatElement *));    /* array of ptrs   */
  ptr = calloc( nr*nc, sizeof(MatElement) ); /* matrix elements */
  for (i=0; i<nr; i++)             /* set row pointers properly */
    A[i] = ptr + nc*i;
  return A;
}

/* Release mamory used by matrix */
void matrix_free(MatElement **A) {
  free(A[0]);
  free(A);
}
 
/* Print matrix elements */
void matrix_print(MatElement **A, char * format, int nr, int nc) {
  int i,j;
  for (i=0; i<nr; ++i) { 
    for (j=0; j<nc; ++j) 
	  printf(format, A[i][j]);
  putchar('\n');
  }
  putchar('\n');
}

/* Create and Identity Matrix */
MatElement **matrix_identity(int n) {
  int i;
  MatElement **A=matrix_alloc(n, n);
  for (i=0; i<n; ++i)
    A[i][i] = (MatElement) 1;
  return A;
}
