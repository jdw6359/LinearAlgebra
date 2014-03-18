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

/* Function Prototypes */

MatElement **matrix_alloc(int nr, int nc);
/*
 * matrix_alloc Allocates memory space for a matrix
 * Inputs: nr and nc (number of rows and columns
 * Output: pointer to a "matrix"
 */

void matrix_free(MatElement **A);
/*
 * matrix_free  releases memory space of a matrix
 * Inputs: the "matrix" to be released
 */

void matrix_print(MatElement **A, char *fs, int nr, int nc);
/*
 * matrix_print prints  a matrix array
 * Inputs: the matrix A, a formatting string fs,
 * number of rows nr, and number of columns nc
 */

MatElement **matrix_identity(int n);
/*
 * matrix_identity generates and indentity matrix
 * Inputs: matrix dimension (n)
 * Output: An n times n identity matrix
 */

#endif
