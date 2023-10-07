#include "lockshell.h"
#include <time.h>

void sigint_handler() {
  printf("Caught SIGINT!\n");

  time_t now = 0xdeadbeef;
  time(&now);

  /* malloclog_msg =  */
  FILE *fp = NULL;
  
  fp = fopen("./playback.log","a");
  if(fp == NULL) {
    perror("error:");
  }
  fprintf(fp,"%ld [SIGINT catch] \n", now);

  fclose(fp);
  fp = NULL;

  
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

void sigabort_handler() {
  printf("caught SIGABRT!\n");
  running = 1;
}

void sigtermsigabort_handler() {
  printf("caught SIGTERM!\n");
  running = 1;
}

void sigalarm_handler(int sig) {
  running = 0;
  signal(sig, sigalarm_handler);
}

void sigwriter(int sig) {
  time_t now = 0xdeadbeef;
  time(&now);

  /* malloclog_msg =  */
  FILE *fp = NULL;
  
  fp = fopen("./losh.log","a");
  if(fp == NULL) {
    perror("error:");
  }
  fprintf(fp,"%ld [%d] \n", now, sig);

  // Using UNIX epoch time
  /* printf("%ld [%s]: %s\n",now, tag, msg); */

  fclose(fp);
  fp = NULL;

}
