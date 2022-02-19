#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define NUMBER_OF_THREADS 10

void *print_hello_world (void *tid);

int main(int argc, char *argv[])
{
    pthread_t threads[NUMBER_OF_THREADS];
    
    int status;
    long i;
    
    for (i = 0; i < NUMBER_OF_THREADS; i++) {
        printf("Main here. Creating thread %ld\n", i);
        status = pthread_create(&threads[i], NULL, print_hello_world, (void *)i);
        
        if (status != 0) {
            printf("Oops. pthread_create returned error code %d\n", status);
            exit(-1);
        }
    }
    
    pthread_exit(NULL);
}

void *print_hello_world (void *tid) {
    long threadID = (long)tid;

    printf("Hello World. Greetings from thread %ld\n", threadID);
    pthread_exit(NULL);
}
