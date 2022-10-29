#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"

#define check(exp, msg) if(exp) {} else {\
   printf(1, "%s:%d check (" #exp ") failed: %s\n", __FILE__, __LINE__, msg);\
   exit();}

#define TICKET_3    30000
#define TICKET_2    20000
#define TICKET_1    10000

int
main(int argc, char *argv[])
{
   struct pstat st;
   int i;

   check(settickets(TICKET_3)==0, "settickets") ;
   check(getpinfo(&st) == 0, "getpinfo");

   //Display process information
   printf(1, "\n**** PInfo ****\n");
   for(i = 0; i < NPROC; i++) {
      if (st.inuse[i]) {
         printf(1, "pid: %d tickets: %d ticks: %d\n", st.pid[i], st.tickets[i], st.ticks[i]);
      }
   }
   exit();
}