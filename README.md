# Lottery Scheduler
Implementing a lottery scheduler for xv6.

# Requirements:
* Implement a new system call to set the number of tickets: int settickets(int)
  - Sets the number of tickets of the calling process
  - By default, each process should get one ticket
  - By calling this routine a process can raise (reduce) the number of tickets it has, and thus receive a higher (lower) proportion of CPU cycles.
  - should return 0 if successful, and -1 otherwise (if, for example, the caller passes in a number less than one).
 
* Assign tickets to a process when it is created.
  - Make sure a child process inherits the same number of tickets as its parent
  
* Implement a system call to gather statistics about all the running processes: int getpinfo(struct pstat*)
  - How many times each process has been chosen to run
  - The process ID
  - Can build a variant of the command "ps"
  - Routine should return 0 if successful, and -1 otherwise (if, for example, a bad or NULL pointer is passed into the kernel).
  
* Make a graph:
  - Show the number of time slices a set of three processes receives over time, where the processes have a 3:2:1 ratio of tickets.
