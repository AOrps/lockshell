#ifndef LOCKSHELL_H
#define LOCKSHELL_H
#include <stdio.h>
#include <signal.h>

extern volatile sig_atomic_t running;


// Signal Handlers
void sigint_handler();
void sigtstp_handler();
void sigquit_handler();
void sigalarm_handler(int);

// Log Writing
void stdout_logger(const char* tag, const char* message);
void file_logger(const char* tag, const char* message, const char* filename);
// Testing


#endif // LOCKSHELL_H
