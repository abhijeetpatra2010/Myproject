Hi all this program illustrates the use of shared memory.In this program when we execute SHMserver and SHMclient the data gets corrupted as shared memory doesnt provide any synchronization.
 We predict the program would give us o/p as:

Value for shmclient:4660 is response
Value for shmserver:4658 is REQUEST

but the o/p shows with corrupted data

Value for shmclient:4660 is REQUEST
Value for shmserver:4658 is response

Hence we should use some form of synchronization method to avoid data corruption .Generally we use Binary Semaphore

To get the above o/p:

1) Generate shmclient (make shmclient)
2) Generate shmserver (make shmserver)
3) Execute shmserver (./shmserver)


