#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

pthread_mutex_t lock;

void *threadFunction(void *arg);

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

    for (int i = 0; i < threadCounts; i++) {
        printf("Main here. Creating thread%d\n", i);
        // create thread
        pthread_create(&newThread[i], NULL, threadFunction, &iterations);
        pthread_join(newThread[i], NULL);
    }

    pthread_mutex_destroy(&lock);

    return 0;
}

// thread function
void *threadFunction(void *arg) {
    pthread_mutex_lock(&lock);

    int *iterations = (int *)arg;

    for (int i = 0; i < *iterations; i++) {
        printf("Hello World. Greetings from thread %d\n", i);
    }

    pthread_mutex_unlock(&lock);

    return NULL;
}