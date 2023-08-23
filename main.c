// #include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lockshell.h"

volatile sig_atomic_t running = 1;

int main() {
  
  // handle interrupts
  signal(SIGINT, sigint_handler);

  // handle quits
  signal(SIGQUIT, sigquit_handler);

  // handle suspends
  signal(SIGTSTP, sigtstp_handler);

  /* time_t *curr_time = NULL; */
  /* printf("%d", TIMER_ABSTIME); */
  
  while(running) {
    continue;
  }

  
  return 0;
}
