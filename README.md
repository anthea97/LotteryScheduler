# Lottery Scheduler
Implementing a lottery scheduler for xv6.

Requirements:
* Implement a new system call to set the number of tickets: int settickets(int)
  - Sets the number of tickets of the calling process
  - By default, each process should get one ticket
  - By calling this routine a process can raise (reduce) the number of tickets it has, and thus receive a higher (lower) proportion of CPU cycles.
  - should return 0 if successful, and -1 otherwise (if, for example, the caller passes in a number less than one).
