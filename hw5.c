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

int main(int argc, char *argv[]){

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

			/* File was opened properly, execute program as expected */
			fprintf(stdout, "Executing Program.....\n");

			/* Declare vars for numRows and numCols of matrix A */
			int numRows, numCols;

			/* Scan numRows and numCols from file */
			fscanf(inputFile, "%d %d", &numRows, &numCols);

			/* Check that numRows and numCols are equal */
			if(numRows!=numCols){

				/* numRows and numCols dont match, alert and exit */
				fprintf(stdout, "Matrix has %d rows and %d columns, not a square matrix.\nExiting...\n", numRows, numCols);
				return 2;

			}



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
