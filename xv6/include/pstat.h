/* The following code is added by axa210122(Anthea Abreo), hxp220011(PH Sai Kiran)
** pstat structure
*/
#ifndef _PSTAT_H_
#define _PSTAT_H_
#include "param.h"


struct pstat {
int inuse[NPROC]; // whether this slot of the process table is in use (1 or 0) 
int tickets[NPROC]; // the number of tickets each process has
int pid[NPROC]; // the PID of each process
int ticks[NPROC]; // the number of times each process has run
};

#endif // _PSTAT_H_
/* End of code added */

