#ifndef LOCKSHELL_H
#define LOCKSHELL_H
#include <stdio.h>
#include <signal.h>

extern volatile sig_atomic_t running;


// Signal Handlers
void sigint_handler();
void sigtstp_handler();
void sigquit_handler();

// Log Writing
void default_write_to();

// Testing


#endif // LOCKSHELL_H
