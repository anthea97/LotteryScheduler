/* The following code is added by axa210122(Anthea Abreo), hxp220011(P H Sai Kiran) */

/*
** graph.c
** The graph should show the number of time slices a set of three processes receives over time,
where the processes have a 3:2:1 ratio of tickets (e.g., process A might have 30 tickets,
process B 20, and process C 10).
*/
#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"

#define check(exp, msg) if(exp) {} else {\
   printf(1, "%s:%d check (" #exp ") failed: %s\n", __FILE__, __LINE__, msg);\
   exit();}

#define PROC 3
#define TICKET_MULT 1000

void spin()
{
	int i = 0;
  int j = 0;
  int k = 0;
	for(i = 0; i < 50; ++i)
	{
	    for(j = 0; j < 10000000; ++j)
		{
            k = j % 10;
            k = k + 1;
        }
	}
}

int
main(int argc, char *argv[])
{
    struct pstat st;
    int i = 0;  
    int pid[NPROC];
     
    check(settickets(TICKET_MULT) == 0, "settickets");

    while(i < PROC){
        pid[i] = fork();

        if(pid[i] == 0){
            check(settickets((i+1)*TICKET_MULT) == 0, "settickets");
            spin();
            exit();
        }
        else if (pid[i] == -1){
	        printf(1, "Fork Failed");
	      }
        i++;
    }

    sleep(500);

    check(getpinfo(&st) == 0, "getpinfo");
    printf(1, "\n**** PInfo ****\n");

    for(i = 0; i < NPROC; i++) {
        if (st.inuse[i]) {
            printf(1, "pid: %d tickets: %d ticks: %d\n", st.pid[i], st.tickets[i], st.ticks[i]);
        }
    }

    while (wait() > 0);
    exit();
}
/* End of code added */
