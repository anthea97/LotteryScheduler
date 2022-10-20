#include "types.h"
#include "x86.h"
#include "defs.h"
#include "param.h"
#include "mmu.h"
#include "proc.h"
#include "sysfunc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return proc->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = proc->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;
  
  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(proc->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since boot.
int
sys_uptime(void)
{
  uint xticks;
  
  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

/* The following code is added by axa210122(Anthea Abreo), hxp220011(PH Sai Kiran)
  ** settickets()
  ** Allocates tickets to the process
  ** Returns 0 if tickets successfully allocated
  ** Returns -1 otherwise
*/
int 
sys_settickets(int ptickets){

} 

/* 
  ** getpinfo()
  **  
  ** Returns 0 if successful, -1 otherwise
*/
int
sys_getpinfo(struct pstat*){

  struct proc *p;

  acquire(&ptable.lock);

  for(int i = 0; i < NPROC; i++){
    //if process is unused
      //Set pids[i]
      //Set ticks[i]
      //Set tickets[i]
    }
  }


/* End of code added */


