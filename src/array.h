#include "process.h"
#ifndef ARRAY_H
#define ARRAY_H

#include "process.h"

#define NUM_PROCESSES 10

// Wrapper for an array to be passed around
typedef struct parray
{
  Process* processes[NUM_PROCESSES];
} PArray;

PArray* create();
bool hasWaitingProcesses(PArray* array);

void print(PArray* array);
void fifo(PArray* array);
void shortestTime(PArray* array);
void priority(PArray* array);

/* Execute the processes in the array */
void execute(PArray* array);
void executeRoundRobin(PArray* array);

#endif 
