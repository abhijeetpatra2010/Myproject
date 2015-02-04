# Main Makefile

MAKE= make -C
MAKE_CLEAN= make clean -C

all:
	$(MAKE) Dynamic
	$(MAKE) Static
	$(MAKE) Fork
	$(MAKE) Multithread
	$(MAKE) Signal
	$(MAKE) ipc/NamedPipe/fifo
	$(MAKE) ipc/SharedMemory
	$(MAKE) Synchronization/Thread
	$(MAKE) Synchronization/Semaphore
	$(MAKE) Socket

clean:	
	$(MAKE_CLEAN) Dynamic
	$(MAKE_CLEAN) Static
	$(MAKE_CLEAN) Fork
	$(MAKE_CLEAN) Multithread
	$(MAKE_CLEAN) Signal
	$(MAKE_CLEAN) ipc/NamedPipe/fifo
	$(MAKE_CLEAN) ipc/SharedMemory
	$(MAKE_CLEAN) Synchronization/Thread
	$(MAKE_CLEAN) Synchronization/Semaphore
	$(MAKE_CLEAN) Socket
