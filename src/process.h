#ifndef PROCESS_H
#define PROCESS_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MAX_PROCESS_TIME 10
#define MAX_PRIORITY 10

typedef struct process
{
  int id;
  int time;
  int priority;
} Process;

/* Seed the random number generator */
void seed();

/* Creates a process */
Process* forkSim(Process* parent);

#endif /* PROCESS_H */
