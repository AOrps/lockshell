// #include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <assert.h>
#include "lockshell.h"


// TIMEOUT in Seconds
#define LOSH_TIMEOUT 30

volatile sig_atomic_t running = 1;



int main() {

  // Ensure it begins running
  assert (running==1);

  /* stdout_logger("start", "someone was caught"); */
  file_logger("hit", "trapped someone", "./losh.log");

  // handles
  signal(SIGALRM, sigalarm_handler);

  
  alarm(LOSH_TIMEOUT);

   
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
