# OS-Assignment1
# Charles Gale
# 28 March 2025

# The code for this assignment can be found in the "master" branch

# The assignment instructions were as follows:
  The producer generates items and puts items onto the table. 
  The consumer will pick up items. 
  The table can only hold two items at the same time. 
  When the table is complete, the producer will wait. 
  When there are no items, the consumer will wait. 
  We use semaphores to synchronize producer and consumer.  
  Mutual exclusion should be considered. 
  We use threads in the producer program and consumer program. 
  Shared memory is used for the “table”.

# the code can be comipled and run with the following commands:
  gcc producer.cpp -pthread -lrt -lstdc++ -o producer
  gcc consumer.cpp -pthread -lrt -lstdc++ -o consumer
  ./producer & ./consumer &
