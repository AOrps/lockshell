// #include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "lockshell.h"

volatile sig_atomic_t running = 1;

/* void timeout(long TIMEOUT_ADD) { */
/*   time_t start = time(NULL); */

/*   printf("start:   [%ld]\n", start); */

/*   long timeout = start + TIMEOUT_ADD; */

/*   while(time(NULL) - start > TIMEOUT_ADD) { */
/*       signal(SIGINT, sigint_handler); */

/*       // handle quits */
/*       signal(SIGQUIT, sigquit_handler); */

/*       // handle suspends */
/*       signal(SIGTSTP, sigtstp_handler); */

/*       /\* time_t *curr_time = NULL; *\/ */
/*       /\* printf("%d", TIMER_ABSTIME); *\/ */
  
/*       while(running) { */
/* 	continue; */
/*       } */

/*   }  */
/*   printf("timeout: [%ld]\n", timeout);   */
  
/* } */


int main() {

  
  
  /* stdout_logger("start", "someone was caught"); */
  file_logger("hit", "trapped someone", "./losh.log");

  /* long TIMEOUT = 10; */
  
  /* time_t start = (long)time(NULL); */

  /* printf("start:   [%ld]\n", start); */

  /* long timeout = start + TIMEOUT; */

  /* printf("timeout:   [%ld]\n", timeout);   */

  /* printf("try:   [%ld]\n", time(NULL) - start); */

  /* sigtimedwait */
  alarm(3);
  
  /* while((time(NULL) - start) < TIMEOUT) { */

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
