#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

// Shared table (buffer)
int table[2];
int itemIndex = 0; // Index for adding and removing items

// Semaphores and mutex
sem_t empty; // keeps track of available slots in the table
sem_t full;  // keeps track of how many items are in the table 
pthread_mutex_t mutex;

