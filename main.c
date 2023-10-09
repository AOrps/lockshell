#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <assert.h>
#include "lockshell.h"

volatile sig_atomic_t running = 1;

int main(int argc, char* argv[]) {

  // Ensure it is set to running before it begins running
  assert (running==1);

  // Instantiations
  // todo:
  // - get standard unix epoch time
  // - get unix epoch time with nanosseconds for greater accuracy

  struct timespec res;
  
  time_t curr = time(NULL);
  char identifier[128];
  clock_gettime(CLOCK_REALTIME,&res);
  long currNano = res.tv_nsec;
  snprintf(identifier, 128, "%x-%ld.%ld", "%x",curr, currNano);
  printf(LOSH_PLAYBACK, identifier);
  
  
  exit(1);
  
  /* stdout_logger("start", "someone was caught"); */
  file_logger("hit", "trapped someone", LOSH_LOG);

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
