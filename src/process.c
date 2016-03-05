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
    pid = ++parent->id;
  }

  printf("ID: %d\n", pid);

  Process* process = malloc(sizeof(Process));
  process->id = pid;
  process->time = rand() % MAX_PROCESS_TIME;
  process->priority = rand() % MAX_PRIORITY;
  
  /* Shift the priority & time from 0 to 9 -> 1 to 10 */
  process->time++;
  process->priority++;

  return process;
}
