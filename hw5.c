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
	MatElement **vector;

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

			/* Call to allocate memory for vector */
			vector=matrix_alloc(numRows,1);

			/* For each row, read in value for each column, in
			 * addition to permutation value at end of row */
			for(rowCounter=0;rowCounter<numRows;rowCounter++){

				/* Declare variable for value stored in perm vector */
				double permValue;

				/* Loop over cols of each row */
				for(colCounter=0;colCounter<numCols;colCounter++){

					/* Declare variable for value stored in amtrix */
					double matValue;

					/* Grab value for matrix at A[rowCounter][colCounter] */
					fscanf(inputFile, "%lf", &matValue);

					/* Set matrix value at [rowCount][colCount] */
					matrix[rowCounter][colCounter]=matValue;

				}
				/* End for over cols */

				/* Scan value for permutation vector */
				fscanf(inputFile, "%lf", &permValue);

				/* Set value at rowCounter,0 */
				vector[rowCounter][0]=permValue;

			}
			/* End for over rows */

			fprintf(stdout,"Original matrix:\n");

			/* Print original matrix and vector */
			matrix_print(matrix, "%g", numRows, numCols);
			matrix_print(vector, "%g", numRows,1);

			/* make call to decomp */
			linalg_LU_decomp(matrix,vector, numRows);

			fprintf(stdout,"New matrix: \n");

			/* Print new matrix */
			matrix_print(matrix, "%g", numRows,numCols);
			matrix_print(vector, "%g", numRows,1);

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
