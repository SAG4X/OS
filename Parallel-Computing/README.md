## Parallel Computing using pthread and OpenMPI and compare the speedup and efficiency metrics of parallel computation

### Step 1 : Sequential C Fragment

Before jump up to parallel, there should a relevent sequential code segment. As per this example, it is a vector dot product using 3 vectors

### Step 2 : pThread C code Fragment

pthread is a parallel computing software library to support multithreaded shared memory computers to run c code.

In the given example, it defined the num of thread as 4, but you can as per your own, as the same time make sure that how many threads your computer consist with.

 ```slave()``` function is the work carried out in parallel

```pthread_create()```, ```pthread_join()``` functions inistize the threads and pass out the work and aggregate the results. 

### Step 3 : OMP C code fragment

OMP defined its own directives to run parallel programs

```#pragma omp parallel``` is the keyword to specify the certain program to be run in parallel. It also enables us to specify the number of threads in different ways. Changing the Environment variable, specify the number of threads we want to integrate as an additional parameter by ```num_of_threads()``` , otherwise it operates on default number of threads available in the machine. Eg :- Quad Core - 4 Threads

There are main three work construct to carry parallel working inside the code. They are ``For`` , ``Section`` and ``Single``. 
For construct to run different iteration with different threads which used in the given example.

