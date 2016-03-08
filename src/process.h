#ifndef PROCESS_H
#define PROCESS_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/* I'm using C99 so I can do this */
#include <stdbool.h>

#define MAX_PROCESS_TIME 15
#define MAX_PRIORITY 3

typedef struct process
{
  int id;
  int time;
  int priority;
  bool completed;
} Process;

/* Seed the random number generator */
void seed();

/* Creates a process */
Process* forkSim(Process* parent);

#endif /* PROCESS_H */
