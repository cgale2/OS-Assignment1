#include "producer_consumer.hpp"

// Producer function
void* producer(void* arg) {
    for (int i = 1; i <= 10; ++i) {
        sem_wait(&empty); // Wait for an empty slot
        pthread_mutex_lock(&mutex); // Lock shared memory for mutual exclusion

        table[itemIndex] = i;
        std::cout << "Producer produced item " << i << std::endl;
        itemIndex = (itemIndex + 1) % 2; // Circular buffer logic

        pthread_mutex_unlock(&mutex); // Unlock after the critical section
        sem_post(&full); // Signal that an item is available

        sleep(1); // Simulate production time
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
    pthread_create(&producerThread, nullptr, producer, nullptr);

    // Wait for threads to finish
    pthread_join(producerThread, nullptr);

    // Destroy semaphores and mutex
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}