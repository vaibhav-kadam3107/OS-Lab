#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int buffer_index = 0;
pthread_mutex_t mutex;

void* producer(void* args) {
    for (int i = 0; i < 20; i++) {
        pthread_mutex_lock(&mutex);

        // Wait for space in the buffer
        while (buffer_index == BUFFER_SIZE) {
            pthread_mutex_unlock(&mutex);
            pthread_yield(); // Give other threads a chance to run
            pthread_mutex_lock(&mutex);
        }

        // Add item to buffer
        buffer[buffer_index++] = i;

        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

void* consumer(void* args) {
    for (int i = 0; i < 20; i++) {
        pthread_mutex_lock(&mutex);

        // Wait for an item in the buffer
        while (buffer_index == 0) {
            pthread_mutex_unlock(&mutex);
            pthread_yield(); // Give other threads a chance to run
            pthread_mutex_lock(&mutex);
        }

        // Remove item from buffer
        int item = buffer[--buffer_index];
        printf("Consumer %d consumed %d\n", *((int*)args), item);

        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t producer_thread, consumer_threads[3];
    int consumer_args[3] = { 1, 2, 3 };

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&producer_thread, NULL, producer, NULL);

    for (int i = 0; i < 3; i++) {
        pthread_create(&consumer_threads[i], NULL, consumer, &consumer_args[i]);
    }

    pthread_join(producer_thread, NULL);

    for (int i = 0; i < 3; i++) {
        pthread_join(consumer_threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    return 0;
}
