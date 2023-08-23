#include "lockshell.h"
#include <time.h>
#include <string.h>

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
