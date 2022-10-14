#include <omp.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

#define N 100000

struct timeval startwtime, endwtime;
double seq_time;

void getvec(double *a);
double dotprod(double *a, double *b, int n);

// initialize the vectors with i/(N+i) values
void getvec(double *a)
{
    int i = 0;
    for (i = 0; i < N; i++)
        a[i] = (double)i / (double)(N + i);
}

double dotprod(double *a, double *b, int n)
{
    int i;
    double s = 0.0;
    // for work construct with chunk
    #pragma omp parallel for reduction(+:s)
    for (i = 0; i < n; i++)
        s += a[i] * b[i];
    return s;
}

int main()
{
    int n = N;
    double *a, *b;

    a = (double *)malloc(sizeof(double) * N);
    b = (double *)malloc(sizeof(double) * N);

    getvec(a);
    getvec(b);

    gettimeofday(&startwtime, NULL);
    double dp = dotprod(a, b, n);
    gettimeofday(&endwtime, NULL);
    seq_time = (double)((endwtime.tv_sec + endwtime.tv_usec*1.0e-6) - (startwtime.tv_sec + startwtime.tv_usec*1.0e-6));

    printf("Result : %f\n", dp);
    printf("Time Elapsed for OpenMP code : %.8f\n", seq_time);

    return 0;
}