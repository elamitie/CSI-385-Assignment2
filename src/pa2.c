#include "process.h"

#define NUMBER_PROCESSES 10
#define DEBUG 1

int main()
{
  seed();

  Process* processes[NUMBER_PROCESSES];
  int i = 1;

  /* Make the parent */
  processes[0] = forkSim(NULL);

  for (; i < NUMBER_PROCESSES; i++)
  {
    processes[i] = forkSim(processes[i - 1]);
  }

#if DEBUG
  for (i = 0; i < NUMBER_PROCESSES; i++)
  {
    printf("Process with id: %d\n", processes[i]->id);
    printf("Process has time: %d\n", processes[i]->time);
    printf("Process has priority: %d\n", processes[i]->priority);
  }
#endif

  return 0;
}
