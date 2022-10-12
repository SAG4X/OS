## Parallel Computing using pthread and OpenMPI and compare the speedup and efficiency metrics of parallel computation

### Step 1 : Sequential C Fragment

Before jump up to parallel, there should a relevent sequential code segment. As per this example, it is a vector dot product using 3 vectors

### Step 2 : pThread C code Fragment

pthread is a parallel computing software library to support multithreaded shared memory computers to run c code.

In the given example, it defined the num of thread as 4, but you can as per your own, as the same time make sure that how many threads your computer consist with.

 ```slave()``` function is the work carried out in parallel

```pthread_create()```, ```pthread_join()``` functions inistize the threads and pass out the work and aggregate the results. 

#### How to Compile 

```
gfg@ubuntu:~/$ gcc pthread-creation.c -lpthread
gfg@ubuntu:~/$ ./a.out
Before Creation of Thread
Printing GeeksQuiz from Thread 
After Creation of Thread
gfg@ubuntu:~/$ 
```
