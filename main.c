#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <assert.h>
#include "lockshell.h"


// TIMEOUT in Seconds
#define LOSH_TIMEOUT 10
#define OPTS_ARGS "hf:"


volatile sig_atomic_t running = 1;

int main(int argc, char* argv[]) {

  // Ensure it is set to running before it begins running
  assert (running==1);
  
  /* stdout_logger("start", "someone was caught"); */
  file_logger("hit", "trapped someone", "./losh.log");

  alarm(LOSH_TIMEOUT);

  /* // handles alarm */
  /* signal(SIGALRM, sigalarm_handler); */
  
  /* // handle interrupts */
  /* signal(SIGINT, sigint_handler); */

  /* // handle quits */
  /* signal(SIGQUIT, sigquit_handler); */

  /* // handle suspends */
  /* signal(SIGTSTP, sigtstp_handler); */

  /* // handle an abort */
  /* signal(SIGABRT, sigabort_handler); */


   
  /* time_t *curr_time = NULL; */
  /* printf("%d", TIMER_ABSTIME); */

  /* FILE *fp = NULL; */

  while(running) {
    /* fp = fopen("playback-try.log","a");   */
    /* int c = getchar(); */
    /* printf("%c -> %d\n",(char)c, c); */

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

    
    /* signal(SIGINT, sigwriter); */
    /* /\* signal(SIGALRM, sigwriter); *\/ */

    /*
      Notes for me;
      It's very difficult to record, backspace (DEL) and signals.
      A quit / CTRL+D will keep filling out anything that tries recording it with a bunch of -1.
      Maybe I can do a getchar with to filter out everything except a '-1', but doesn't
      fix the backspace not being filled problem
     */
    
    /* fprintf(fp, "%d-",c); */
    /* fclose(fp);     */

    
    continue;
  }
  
  return 0;
}
