/***************************************************************/
/* Driver program for the linalg modules developed for hw5     */
/* Run from the command line, will read in test matrix data    */
/* and perform operations defined in linalg.c                  */
/*                                                             */
/* Author: Josh Woodward				       */
/* Date: 3/26/2014 					       */
/***************************************************************/

/* include necessary c libraries */
#include <stdlib.h>
#include <stdio.h>
#include "linalg.h"

int main(int argc, char *argv[]){

	/* Declare vars that hold numRow and numCols values scanned from txt file */
	int numRows, numCols;

	/* Declare pointer to matrix */
	MatElement **matrix;

	/* Declare pointer to vector */
	VectorElement *perm, *solved;


	/* Declare row and column values to loop over rows / cols */
	int rowCounter, colCounter;

	/* Check to make sure there are the correct number of cmdline args */
	if(argc==2){

		/* Declare FILE variable */
		FILE* inputFile;

		/* Attempt to open file provided in cmdline arg */
		inputFile=fopen(argv[1],"r");

		/* Check to make sure file was opened properly */
		if(inputFile==NULL){

			/* Alert user file was not opened properly */
			fprintf(stdout,"\nFile was not opened properly\n");
			return 2;

		}else{

			/* Scan numRows and numCols from file */
			fscanf(inputFile, "%d %d", &numRows, &numCols);

			/* Check that numRows and numCols are equal */
			if(numRows!=numCols){

				/* numRows and numCols dont match, alert and exit */
				fprintf(stdout, "Matrix has %d rows and %d columns, not a square matrix.\nExiting...\n", numRows, numCols);
				return 0;
			}

			/* Call matrix_alloc to allocate memory for matrix */
			matrix=matrix_alloc(numRows,numCols+1);

			/* Call vector_alloc to allocate memory for vector */
			perm=vector_alloc(numRows);
			solved=vector_alloc(numRows);

			/* Call perm_vector_initialize to initialize values of
			   perm vector used in the elimination process */
			vector_initialize(perm, numRows, 1);
			vector_initialize(solved, numRows, 0);

			/* For each row, read in value for each column, in
			 * addition to permutation value at end of row */
			for(rowCounter=0;rowCounter<numRows;rowCounter++){

				/* Loop over cols of each row */
				for(colCounter=0;colCounter<numCols+1;colCounter++){

					/* Declare variable for value stored in amtrix */
					double matValue;

					/* Grab value for matrix at A[rowCounter][colCounter] */
					fscanf(inputFile, "%lf", &matValue);

					/* Set matrix value at [rowCount][colCount] */
					matrix[rowCounter][colCounter]=matValue;

				}
				/* End for over cols */

			}
			/* End for over rows */

			fprintf(stdout, "Original Matrix: \n");
			matrix_print(matrix, " %g ", numRows, numCols);

			vector_print(perm, " %d ", numRows);

			/* make call to decomp */
			linalg_LU_decomp(matrix,perm,numRows);

			fprintf(stdout, "Matrix after decomposition \n");
			matrix_print(matrix, " %g ", numRows, numCols);
			vector_print(perm, " %d ", numRows);


			/* make call to solve */

			linalg_LU_solve(matrix,perm,solved);




			fprintf(stdout,"Freeing matrix\n");
			matrix_free(matrix);

			fprintf(stdout,"Freeing vector\n");
			vector_free(perm);
			vector_free(solved);

		}
		/* End check for valid input file */

	}else{

		/* Alert user to proper usage */
		fprintf(stdout,"Usage: ./linalg <xxxx.txt>\n");
		return 1;

	}
	/* End check for cmdline args */


	/* Program completed successfully, return 0 to user */
	return 0;

}
/* end main method */
