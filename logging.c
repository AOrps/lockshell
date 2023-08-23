#include "lockshell.h"
#include <time.h>

void logger(const char* tag, const char* msg) {
  time_t now = 0x0;
  time(&now);
  printf("%s [%s]: %s\n", ctime(&now), tag, msg);
}
/* void write */
