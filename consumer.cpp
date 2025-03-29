#include "producer_consumer.hpp"

// Consumer function
void* consumer(void* arg) {
    for (int i = 1; i <= 10; ++i) {
        sem_wait(&full); // Wait for an available item
        pthread_mutex_lock(&mutex); // Lock shared memory for mutual exclusion

        int item = table[(itemIndex - 1 + 2) % 2]; // Get item from buffer
        std::cout << "Consumer consumed item " << item << std::endl;

        pthread_mutex_unlock(&mutex); // Unlock after the critical section
        sem_post(&empty); // Signal that a slot is available

        sleep(1); // Simulate consumption time
    }
    return nullptr;
}

int main() {
    pthread_t producerThread, consumerThread;

    // Initialize semaphores and mutex
    sem_init(&empty, 0, 2); // Table has 2 empty slots initially
    sem_init(&full, 0, 0);  // Table is initially empty
    pthread_mutex_init(&mutex, nullptr);

    // Create threads
    pthread_create(&consumerThread, nullptr, consumer, nullptr);

    // Wait for threads to finish
    pthread_join(consumerThread, nullptr);

    // Destroy semaphores and mutex
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}