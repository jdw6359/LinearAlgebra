/**********************************************************************
 * gsl_sample
 * This files shows how to use the GSL (GNU Scientify Library) to solve 
 * a system of algebraic equations Ax=b via Gaussian elimination, more 
 * precisely using the PLU factorization.
 *
 * Compile: gcc -o test_gsl gsl_sample.c -lgsl -lgslcblas
 *
 * Revision : Juan C. Cockburn, 19/24/2013, 3/18/2014
 * Reference: Golub and Van Loan 3rd Ed, Algorithm 3.4.1, pg 112.
 **********************************************************************/
     #include <stdio.h>
     #include <gsl/gsl_linalg.h>

     int main (void) {
       /* Local variables */
       int i, j, k, l; /* Indices and counters       */
       int nr = 3;     /* Matrix dimensions, rows    */
       int nc = 3;     /* Matrix dimensions, columns */
       int s;          /* Sign of the permutation    */
       /* Declare and allocate matrix and vector variables */
       gsl_matrix *A = gsl_matrix_calloc (nr,nc) ;      /* Coefficient Matrix        */
       gsl_vector *b = gsl_vector_calloc (nr) ;         /* Coefficient Vector        */
       gsl_vector *x = gsl_vector_calloc (nc);          /* Solution Vector           */
       gsl_permutation *p = gsl_permutation_alloc (nr); /* Permutation Vector  for LU */

       /* Example data */
       /* A 3x3 matrix */
       double a_data[] = { 2.00, 1.00, 1.00,
                           4.00,-6.00, 0.00,
                          -2.00, 7.00, 2.00 } ;
       /* b 3-vector */
       double b_data[] = { 5.00, -2.00, 9.00 };

       /* Initialize coefficient matrix (A) and vector (b) */
       k = 0 ; l = 0 ; /* set counters  to zero */
       for (i=0;i<nr;i++) {
         for (j=0;j<nc;j++) {
            gsl_matrix_set(A,i,j,a_data[k]) ; 
            k++ ;
         } /* for j */
         gsl_vector_set(b,i,b_data[l]) ; 
         l++ ;
       } /* for i */
       
       /* Print entries of A            */
       /* do not use gsl_matrix_fprintf */
       printf("Solution of the system Ax=b via PLU factorizations\n");
       printf("Matrix A:\n");
       for (i = 0; i < nr; i++) {
         for (j = 0; j < nc; j++)
           printf ("%7.2g ", gsl_matrix_get (A, i, j));
       putchar('\n');
       } /* for i */
       
       /* Print entries of vector b */
       printf("Vector b:\n");
       gsl_vector_fprintf (stdout, b,"%7.2g") ;

       /* Perform (inplace) PLU factorization:  overwrites A    */
       gsl_linalg_LU_decomp (A, p, &s); /* A is overwritten     */
       /* Now solve using the data in A and p found above and b */
       gsl_linalg_LU_solve (A, p, b, x); /* x returns retuls    */

       /* Print solution x */
       printf("Solution x:\n");
       gsl_vector_fprintf (stdout, x, "%7.2g");
     
       /* free up memory dynamically allocated */
       gsl_matrix_free (A);
       gsl_vector_free (b);
       gsl_permutation_free (p);
       gsl_vector_free (x);

       return 0;
     } /* main */
