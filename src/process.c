#include "process.h"

void seed()
{
  time_t t;
  srand((unsigned)time(&t));
}

Process* forkSim(Process* parent)
{
  int pid = 0;

  if (parent != NULL)
  {
    pid = parent->id + 1;
  }

  Process* process = malloc(sizeof(Process));
  process->id = pid;
  process->time = rand() % MAX_PROCESS_TIME;
  process->priority = rand() % MAX_PRIORITY;
  
  /* Shift the priority & time from 0 to 9 -> 1 to 10 */
  process->time++;
  process->priority++;

  return process;
}

void printProcesses(int start, int numProcesses, Process* processes[])
{
  int iter = start;

  for (iter; iter < numProcesses; iter++)
  {
    printf("------------------------\n");
    printf("Process with id: %d\n", processes[iter]->id);
    printf("Process has time: %d\n", processes[iter]->time);
    printf("Process has priority: %d\n", processes[iter]->priority);
  }
}
