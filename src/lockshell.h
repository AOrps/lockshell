#ifndef LOCKSHELL_H
#define LOCKSHELL_H
#include <stdio.h>
#include <signal.h>

// Build Options

// TIMEOUT in seconds
#define LOSH_TIMEOUT 3

// Logging File
#define LOSH_LOG "./losh.log"

// Log Format (to put onto %s)
#define LOG_FORMAT "%s-%ld-%ld"

// Playback on the Shell
#define LOSH_PLAYBACK "./playback-%s.log"


extern volatile sig_atomic_t running;

// Signal Handlers
void sigint_handler();
void sigtstp_handler();
void sigquit_handler();
void sigalarm_handler(int);
void sigabort_handler();
void sigterm_handler();
void sigwriter(int);

// Log Writing
struct identifier {
    long Epoch;
    long Nanosec;
    char Unique[20];
};
void f_log(char*, struct identifier*, const char*);
void stdout_logger(const char* tag, const char* message);
void file_logger(const char* tag, const char* message, const char* filename);
void new_id(struct identifier*);



// Testing




#endif // LOCKSHELL_H


