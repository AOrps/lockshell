#include "lockshell.h"

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

void sigalarm_handler(int sig) {
  running = 0;
  signal(sig, sigalarm_handler);
}
