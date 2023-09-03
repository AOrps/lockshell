// #include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "lockshell.h"

volatile sig_atomic_t running = 1;



int main() {

  
  
  /* stdout_logger("start", "someone was caught"); */
  file_logger("hit", "trapped someone", "./losh.log");

  signal(SIGALRM, sigalarm_handler);
  
  alarm(3);

   
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
  /* } */
  
  return 0;
}
