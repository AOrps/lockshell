#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

volatile sig_atomic_t running = 1;

void sigint_handler(int signum) {
  printf("Caught SIGINT!\n");
  running = 1;
}

void sigtstp_handler(int signum) {
  printf("Caught SIGTSTP\n");
  running = 1;
}

void sigquit_handler(int signum) {
  printf("Caught SIGQUIT!\n");
  running = 1;
}


int main() {
  // handle interrupts
  signal(SIGINT, sigint_handler);

  // handle quits
  signal(SIGQUIT, sigquit_handler);

  // handle suspends
  signal(SIGTSTP, sigtstp_handler);
  
  while(running) {
    if(running == 1) {
      scanf("%s", &input);
      printf("> %s", &input);
    // continue;
    } else {
      continue;
    }
  }

  
  return 0;
}
