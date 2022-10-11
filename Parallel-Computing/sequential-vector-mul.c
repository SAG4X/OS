#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

#define N 10000000

double time_sequential;
struct timeval startwtime, endwtime;

/* Function Declarations */
void getvec(double *a);
double dotprod(double *x, double *y, double *z, int n);

/* Vector Initialization */
void getvec(double *a)
{
    int i = 0;
    for (i = 0; i < N; i++)
        a[i] = (double)i / (double)(N + i);
}

/* Dot product of vectors */
double dotprod(double *x, double *y, double *z, int n)
{
    int i;
    double s = 0.0;
    for (i = 0; i < n; i++)
        s += x[i] * y[i] * z[i];
    return s;
}

int main()
{
    int n = N;
    double *a, *b, *c;

    // assign storage to vectors
    a = (double *)malloc(sizeof(double) * N);
    b = (double *)malloc(sizeof(double) * N);
    c = (double *)malloc(sizeof(double) * N);

    getvec(a);
    getvec(b);
    getvec(c);

	// start calculating time
    gettimeofday(&startwtime, 0);
    double dp = dotprod(a, b, c, n);
    gettimeofday(&endwtime, 0);
    // end calculaing time

    // compute time difference
    time_sequential = (double)((endwtime.tv_sec + endwtime.tv_usec*1.0e-6) - (startwtime.tv_sec + startwtime.tv_usec*1.0e-6));

    printf("Result : %f\n", dp);
    printf("Time Elapsed for sequential code : %.8f\n", time_sequential);

    return 0;
}