#ifndef _LINALG_H_
#define _LINALG_H_
/********************************************************
 * A Simple Linear Algebra Module
 * Applied Programming
 * Revised: Juan C. Cockburn 10/24/2013 (jcck@ieee.org)
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>

/* Change MatElement according to the matrix type */
typedef double MatElement; /* For Real matrices */
typedef double VectorElement; /* For simple vector such as permutation vector */

/* Function Prototypes */

MatElement **matrix_alloc(int nr, int nc);
/*
 * matrix_alloc Allocates memory space for a matrix
 * Inputs: nr and nc (number of rows and columns
 * Output: pointer to a "matrix"
 */

VectorElement *vector_alloc(int size);
/*
 * vector_alloc Allocates memory space for a vector
 * Inputs: size (number of "rows": stored in continuous memory,
 * but are representative of rows
 * Output: Pointer to a vector
 */

void matrix_free(MatElement **A);
/*
 * matrix_free  releases memory space of a matrix
 * Inputs: the "matrix" to be released
 */

void vector_free(VectorElement *v);
/*
 * vector_free releases memory space of a vector
 * Inputs: the vector to be released
 */

void matrix_print(MatElement **A, char *fs, int nr, int nc);
/*
 * matrix_print prints  a matrix array
 * Inputs: the matrix A, a formatting string fs,
 * number of rows nr, and number of columns nc
 */

void vector_print(VectorElement *v, char *fs, int size);
/*
 * vector_print prints a vector
 * Inputs: the vector v, a formatting string fs,
 * size of vector size
 */

void right_hand_print(MatElement **A, char *fs, int nr, int nc);
/*
 * right_hand_print prints right hand side of augmented matrix
 */


MatElement **matrix_identity(int n);
/*
 * matrix_identity generates and indentity matrix
 * Inputs: matrix dimension (n)
 * Output: An n times n identity matrix
 */

int linalg_LU_decomp(MatElement **A, MatElement **p, int dim);
/* Implements the in place Gaussian Elimination process with
 * partial pivoting. It should take as input arguments the
 * matrix A and return the results in the overwritten matrix A
 * that encodes the lower part of L and U matrices and the
 * permutaion vector p that defines the permutation matrix P
 */

int linalg_LU_solve(MatElement **A, MatElement **p, VectorElement *b, VectorElement *x, int size);
/* Finds the solution to the system Ax=b given packed LU matrix
 * obtained by the Elimination step above. Should take as input arguments
 * the overwritten matrix A (generated by linalg_LU_decomp), the pivot
 * vector p, the right hand side vector b, and "return" the solution in
 * vector x.
 */

void print_plu(MatElement **A, MatElement **p);
/* "unpack" the matrices L,U, and P, and print them as well */

#endif
