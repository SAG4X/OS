
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>
 
// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
void *slave(void *vargp)
{
    sleep(1);
    printf("Printing GeeksQuiz from Thread \n");
    return NULL;
}
  
int main()
{
    pthread_t thread_id;
    printf("Before Creation of Threads\n");
    // create thread, default threads
    pthread_create(&thread_id, NULL, slave, NULL);
    // aggrgeate works
    pthread_join(thread_id, NULL);
    printf("After Creation of Thread\n");
    exit(0);
}