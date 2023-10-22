#include "lockshell.h"
#include <time.h>
#include <string.h>
#include <stdlib.h>

void new_id(struct identifier* id) {
    char _id[20];
    time_t _epoch;
    struct timespec res;
    long _nanosec;

    // hacky way to get random alphanumeric characters from ambiguous memory
    snprintf(_id, 20, "%x", "%x");

    // get unix epoch
    _epoch = time(NULL);

    // get nanoseconds
    clock_gettime(CLOCK_REALTIME, &res);
    _nanosec = res.tv_nsec;

    // set value to struct
    strcpy(id->Unique,_id);
    id->Epoch = _epoch;
    id->Nanosec = _nanosec;
}


void f_log(char* filename, struct identifier *id, const char* msg) {
    FILE *fp = NULL;
    
    char log_identifier[48];

    printf("sdfkajsfndkasnfd\n");

    printf("%s\n", id->Unique);
    
    snprintf(log_identifier, 48, LOG_FORMAT,id->Unique, id->Epoch, id->Nanosec);

    printf("%s\n", log_identifier);

    snprintf(filename, 64, LOSH_PLAYBACK, log_identifier);
    
    fp = fopen(filename, "a");
    if(fp == NULL) {
        perror("error: with f_log");
    }
    fprintf(fp, msg);

    fclose(fp);
    fp = NULL;

}

void stdout_logger(const char* tag, const char* msg) {
  time_t now = 0xdeadbeef;
  time(&now);

  // Using UNIX epoch time
  printf("%ld [%s]: %s\n",now, tag, msg);

  // Using Locale Time
  // UNIX epoch is more accurate
  /* printf("%s [%s]: %s\n", ctime(&now), tag, msg);   */

}

void file_logger(const char* tag, const char* msg, const char* filename) {
  time_t now = 0xdeadbeef;
  time(&now);

  /* malloclog_msg =  */
  FILE *fp = NULL;
  
  fp = fopen(filename,"a");
  if(fp == NULL) {
    perror("error:");
  }
  fprintf(fp,"%ld [%s]: %s\n", now, tag, msg);

  // Using UNIX epoch time
  /* printf("%ld [%s]: %s\n",now, tag, msg); */

  fclose(fp);
  fp = NULL;
  /* free(fp);  */
  
  // Using Locale Time
  // UNIX epoch is more accurate
  /* printf("%s [%s]: %s\n", ctime(&now), tag, msg);   */

}


