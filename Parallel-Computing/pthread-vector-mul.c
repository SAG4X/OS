#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#include <assert.h>
#include <pthread.h>


#define RANDLIMIT 5 /* Magnitude limit of generated randno.*/
#define N 1024 /* Matrix Size is configurable - Should be a multiple of THREADS */
#define THREADS 8 /* Define Number of Threads */
#define NUMLIMIT 70.0

void *slave (void *myid);

/*Shared Data*/
float a[N][N];
float b[N][N];
float c[N][N];

/* Important Function - This is the function execute by pthreads */
void *slave( void *myid ){
	int x, low, high;
	
	/*Calculate which rows to calculate by each Thread*/
	if (N >= THREADS) { 
		/*When the matrix has more rows than the number of threads */
		x = N/THREADS;
		low = (int) myid * x;
		high = low + x;
	} else {
		/*When the number of Threads is greater than N,
		This prevents the unneccessary running of the for-loop*/
		x = 1;
		low = (int) myid;
		if (low >= N) { //there is nothing to calculate for the extra threads
			high = low;
		} else {
			high = low +1; //each thread will be calculating only one row
		}
	}

	int i, j, k;
	
	/*Calculation*/
	/*mutual exclusion is not needed
	because the each Thread is accessing a different part of the array.
	Therefore the data integrity issue is not involved.*/
	for (i=low; i<high; i++) {
		for (j=0; j<N; j++) {
			c[i][j] = 0.0;
			for (k=0; k<N; k++){
				c[i][j] = c[i][j] + a[i][k]*b[k][j];
			}
		}
	}
}

int main(int argc, char *argv[]){
	struct timeval start, stop;
	int i,j;
	pthread_t tid[THREADS];

		/* generate matrics randomly */
	for (i=0; i<N; i++)
		for (j=0; j<N; j++) {
			a[i][j] = 1+(int) (NUMLIMIT*rand()/(RAND_MAX+1.0));
			b[i][j] = (double) (rand() % RANDLIMIT);
	}
#ifdef PRINT
	/* print matrices A and B */
	printf("\nMatrix A:\n");
	for (i=0; i<N; i++){
		for (j=0; j<N; j++)
			printf("%.3f\t",a[i][j]);
		printf("\n");
	}
	printf("\nMatrix B:\n");
	for (i=0; i<N; i++){
		for (j=0; j<N; j++)
			printf("%.3f\t",b[i][j]);
		printf("\n");
	}
#endif
	/*Start Timing*/
	gettimeofday(&start, 0);
	
	/*Create Threads*/
	for ( i=0; i<THREADS ; i++)
		if (pthread_create( &tid[i], NULL, slave, (void *) i) != 0)
			perror ("Pthread create fails");
	/*Join Threads*/
	for ( i=0; i<THREADS ; i++)
		if (pthread_join( tid[i], NULL) != 0 )
			perror ("Pthread join fails");
			
	/*End Timing*/
	gettimeofday(&stop, 0);
#ifdef PRINT
	/*print results*/
	printf("\nAnswer = \n");
	for (i=0; i<N; i++){
		for (j=0; j<N; j++)
			printf("%.3f\t",c[i][j]);
		printf("\n");
	}
#endif
	/*Print the timing details*/
	fprintf(stdout,"Time for Pthread = %.6f\n\n",(stop.tv_sec+stop.tv_usec*1e-6)-(start.tv_sec+start.tv_usec*1e-6));
	return(0);
}
