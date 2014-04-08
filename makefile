#------------------------------------------------------------------
# Makefile for GNU/Linux system 
# Compiles and tests matrix manipulation and linear system solving
# Author: Josh Woodward 3/26/2014
#------------------------------------------------------------------

## for GCC
CC = gcc

##Compilation Flags set
CFLAGS = -Wall -ansi -pedantic
LFLAGS = -lm
GSLFLAGS = -lgsl -lgslcblas


make: linalg gsl_sample


linalg: hw5.o linalg.o
	$(CC) $(CFLAGS) -o linalg hw5.o linalg.o

hw5.o: hw5.c
	$(CC) $(CFLAGS) -c hw5.c

linalg.o: linalg.c
	$(CC) $(CFLAGS) -c linalg.c

gsl_sample: gsl_sample.o
	$(CC) -o gsl_sample gsl_sample.o $(GSLFLAGS)

gsl_sample.o: gsl_sample.c
	$(CC) -c gsl_sample.c


############ Block used for execution of programs
sample: gsl_sample
	./gsl_sample

test: linalg
	./linalg ge1.txt
	./linalg ge2.txt
	./linalg ge3.txt
	./linalg ge4.txt


clean:
	rm -f *.o
	rm -f *.save
	rm -f *.gch
