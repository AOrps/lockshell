#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

volatile sig_atomic_t running = 1;

void sigint_handler() {
  printf("Caught SIGINT!\n");
  running = 1;
}

void sigtstp_handler() {
  printf("Caught SIGTSTP\n");
  running = 1;
}

void sigquit_handler() {
  printf("Caught SIGQUIT!\n");
  running = 1;
}

// siginfo_t 


int main() {

  //psiginfo()
  
  // handle interrupts
  signal(SIGINT, sigint_handler);

  // handle quits
  signal(SIGQUIT, sigquit_handler);

  // handle suspends
  signal(SIGTSTP, sigtstp_handler);
  
  while(running) {
    continue;
  }

  
  return 0;
}
