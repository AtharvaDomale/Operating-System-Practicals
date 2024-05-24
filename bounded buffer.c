#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 10

int buffer[BUFFER_SIZE];
int in = 0;
int out = 0;

sem_t empty;
sem_t full;
pthread_mutex_t mutex;

void *producer(void *param) {
    int item;
    while (1) {
        item = rand() % 100; // Produce an item
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);

        buffer[in] = item;
        printf("Producer produced %d\n", item);
        in = (in + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex);
        sem_post(&full);

        sleep(1); // Sleep to simulate time taken to produce an item
    }
}

void *consumer(void *param) {
    int item;
    while (1) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);

        item = buffer[out];
        printf("Consumer consumed %d\n", item);
        out = (out + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex);
        sem_post(&empty);

        sleep(1); // Sleep to simulate time taken to consume an item
    }
}

int main() {
    pthread_t tid1, tid2;
    
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&tid1, NULL, producer, NULL);
    pthread_create(&tid2, NULL, consumer, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}




he producer-consumer problem involves two types of threads: producers and consumers, which share a common, fixed-size buffer.
Producers produce items and add them to the buffer, while consumers consume items from the buffer.
The problem arises when producers try to produce items while the buffer is full or consumers try to consume items while the buffer is empty, leading to synchronization issues.
Semaphores are used to control access to the buffer, ensuring mutual exclusion and synchronization between producers and consumers.
Producers wait on a semaphore representing empty slots in the buffer before adding items, and consumers wait on a semaphore representing filled slots before consuming items.