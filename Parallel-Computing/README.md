## Parallel Computing using pthread and OpenMPI and compare the speedup and efficiency metrics of parallel computation

### Step 1 : Sequential C Fragment

Before jump up to parallel, there should a relevent sequential code segment. As per this example, it is a vector dot product using 3 vectors.

### Step 2 : pThread C code Fragment

pthread is a parallel computing software library to support multithreaded shared memory computers to run c code.

In the given example, it defined the num of thread as 4, but you can as per your own, as the same time make sure that how many threads your computer consist with.

 ```slave()``` function is the work carried out in parallel

```pthread_create()```, ```pthread_join()``` functions inistize the threads and pass out the work and aggregate the results. 

#### How to Compile & Run a pthread C code

#### How to Compile 

```
gfg@ubuntu:~/$ gcc pthread-creation.c -lpthread
gfg@ubuntu:~/$ ./a.out
Before Creation of Thread
Printing GeeksQuiz from Thread 
After Creation of Thread
gfg@ubuntu:~/$ 
```

### Step 3 : OMP C code fragment

OMP defined its own directives to run parallel programs

```#pragma omp parallel``` is the keyword to specify the certain program to be run in parallel. It also enables us to specify the number of threads in different ways. Changing the Environment variable, specify the number of threads we want to integrate as an additional parameter by ```num_of_threads()``` , otherwise it operates on default number of threads available in the machine. Eg :- Quad Core - 4 Threads

There are main three work construct to carry parallel working inside the code. They are ``For`` , ``Section`` and ``Single``. 
For construct to run different iteration with different threads which used in the given example.

#### How to Compile & Run a OpenMP C code

```
gfg@ubuntu:~/$ gcc -fopenmp -o go go.c
gfg@ubuntu:~/$ ./go
```

### Step 4 : Measure the Speedup & Efficiency Metrics


### MPI

MPI is a Specification given for the developers to run parallel programs in a cluster environment. MPI has set of ```routings``` to pass the messages on either to ``point-to-point`` as well as ``group``. These are some them.

```
MPI_Init()
MPI_Comm_Rank()
MPI_Comm_Size()
MPI_Send()
MPI_Recv()
```

#### How to Compile & Run a MPI C code

```
gfg@ubuntu:mpicc go_mpi.c -o go_mpi
gfg@ubuntu:mpirun -n 4 go_mpi
```