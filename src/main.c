#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <assert.h>
#include "lockshell.h"

volatile sig_atomic_t running = 1;

struct identifier globalID;


int main(int argc, char* argv[]) {

  // Ensure it is set to running before it begins running
  assert (running==1);

  // Identifier Struct
  struct identifier id;
  new_id(&id);

  globalID = id;

  /* printf("[%s,%ld,%ld]\n",id.Unique, id.Epoch, id.Nanosec); //  DEBUG */
  
  // session_log
  char session_id[64];
  sess_id(session_id, &id);

   /* printf(">%s<\n", session_id); // DEBUG */

  p_log(&id, session_id);
  
  alarm(LOSH_TIMEOUT);

  while(running) {
    
    // handles alarm
    signal(SIGALRM, sigalarm_handler);
    
    // handle interrupts
    signal(SIGINT, sigint_handler);

    // handle quits
    signal(SIGQUIT, sigquit_handler);

    // handle suspends
    signal(SIGTSTP, sigtstp_handler);

    // handle an abort
    signal(SIGABRT, sigabort_handler);
    
    continue;
  }
  
  return 0;
}
