#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *threadFunction(void *arg);

int counter;

int main (int argc, char *argv[]) {
    int threadCounts = 10;
    int iterations = 10000;

    char *threadCount = argv[1];
    char *iteration = argv[2];

    switch(argc) {
        case 3:
            threadCounts =  atoi(threadCount);
            iterations = atoi(iteration);
            break;

        default: 
            printf("Not enough arguments, setting thread count to 10 and iterations to 10,000.\n");
            threadCounts = 10;
            iterations = 10000;
    }

    pthread_t newThread[threadCounts];
    int status;

    for (int i = 0; i < threadCounts; i++) {
        printf("Main here. Creating thread%d\n", i);
        int tas = 0;

        while (tas == 0) {
            // create thread
            status = pthread_create(&newThread[i], NULL, threadFunction, &iterations);
            
            if (status != 0) {
                printf("Oops. pthread_create returned error code %d\n", status);
                exit(-1);
            }
            
            tas = 1;

            sleep(1);
        }
    }

    printf("Counter: %d\n", counter);

    return 0;
}

// thread function
void *threadFunction(void *arg) {
    int *iterations = (int *)arg;

    for (int i = 0; i < *iterations; i++) {
        printf("Hello World. Greetings from thread %d\n", i);
        counter++;
    }

    return NULL;
}