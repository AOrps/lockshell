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

/*
char * getline(void) {
  char * line = malloc(100), *linep = line;
  size_t lenmax=100, len = lenmax;
  int c;

  if(line == NULL)
    return NULL;

  for(;;) {
    c = fgetc(stdin);
    if(c == EOF)
      break;

    if(--len == 0) {
      len = lenmax;
      char * linen = realloc(linep, lenmax *= 2);

      if(linen == NULL) {
	free(linep);
	return NULL;
      }
      line = linen + (line - linep);
      linep = linen;
    }

    if((*line++ = c) == '\n')
      break;
  }
  *line = '\0';
  return linep;
}
*/

int main() {
  // handle interrupts
  signal(SIGINT, sigint_handler);

  // handle quits
  signal(SIGQUIT, sigquit_handler);

  // handle suspends
  signal(SIGTSTP, sigtstp_handler);

  char ** input;
  
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
