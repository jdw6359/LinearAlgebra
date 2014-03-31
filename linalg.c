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
	for (i=0; i<nr; i++) {
		for (j=0; j<nc; j++){
			fprintf(stdout," %g ", A[i][j]);
		}
		putchar('\n');
	}
}

/* Create and Identity Matrix */
MatElement **matrix_identity(int n) {
  int i;
  MatElement **A=matrix_alloc(n, n);
  for (i=0; i<n; ++i)
    A[i][i] = (MatElement) 1;
  return A;
}

int linalg_LU_decomp(MatElement **A, MatElement **b, int dim){

	int k,row,col;

	double pivot;


	fprintf(stdout,"Decomp called\n");


	for(k=0;k<dim;k++){

		fprintf(stdout,"This is the %d th iteration\n", k);

		pivot=A[k][k];

		fprintf(stdout, "Pivot set to: %g\n", pivot);

		for(row=k+1;row<dim;row++){
			fprintf(stdout,"Row is: %d",row);
		}

	}
	/* End k looping */


	return 0;

}
/* Implements the in place Gaussian Elimination process with
 * partial pivoting. It should take as input arguments the
 * matrix A and return the results in the overwritten matrix A
 * that encodes the lower part of L and U matrices and the
 * permutaion vector p that defines the permutation matrix P
 */

int linalg_LU_solve(MatElement **A, MatElement **p, MatElement **b, MatElement **x){

	fprintf(stdout, "solve called\n");
	return 0;
}
/* Finds the solution to the system Ax=b given packed LU matrix
 * obtained by the Elimination step in decomp. Should take as input
 * arguments the overwritten matrix A (generated by linalg_LU_decomp),
 * the pivot vector p, the right hand side vector b, and "return"
 * the solution in vector x.
 */

void print_plu(MatElement **A, MatElement **p){

	fprintf(stdout, "print called\n");

}
/* unpack the matrices L, U, and P, and print them as well */
