#include "array.h"

PArray* create()
{
  PArray* array = (PArray*)malloc(sizeof(PArray));
  return array;
}

bool hasWaitingProcesses(PArray* array)
{
  for (int i = 0; i < NUM_PROCESSES; i++)
  {
    if (array->processes[i]->completed == false)
      return true;
  }

  return false;
}

void print(PArray* array)
{
  for (int i = 0; i < NUM_PROCESSES; i++)
  {
    printf("--------------------\n");
    printf("Process w/ ID: %d\n", array->processes[i]->id);
    printf("Execution Time: %d\n", array->processes[i]->time);
    printf("Priority Number: %d\n", array->processes[i]->priority);
  }  
}

void fifo(PArray* array)
{
  array->processes[0] = forkSim(NULL);
  for (int i = 1; i < NUM_PROCESSES; i++)
  {
    array->processes[i] = forkSim(array->processes[i - 1]);
  }
}

void shortestTime(PArray* array)
{
  Process* swap;

  for (int i = 0; i < (NUM_PROCESSES - 1); i++)
  {
    for (int j = 0; j < NUM_PROCESSES - i - 1; j++)
    {
      if (array->processes[j]->time > array->processes[j + 1]->time)
      {
        swap                    = array->processes[j];
        array->processes[j]     = array->processes[j + 1];
        array->processes[j + 1] = swap;
      }    
    }
  }
}

void priority(PArray* array)
{
  Process* swap;

  for (int i = 0; i < (NUM_PROCESSES - 1); i++)
  {
    for (int j = 0; j < NUM_PROCESSES - i - 1; j++)
    {
      if (array->processes[j]->priority > array->processes[j + 1]->priority)
      {
        swap = array->processes[j];
        array->processes[j] = array->processes[j + 1];
        array->processes[j + 1] = swap;
      }
    }
  }
}

void execute(PArray* array)
{
  float totalTime = 0.0f;
  float averageTime;

  for (int i = 0; i < NUM_PROCESSES; i++)
  {
    totalTime += array->processes[i]->time;  
  }

  averageTime = totalTime / (float)NUM_PROCESSES;
  
  print(array);
  printf("-----------------\n");
  printf("Time taken to execute queue: %f\n", totalTime);
  printf("Average time to execute a processes: %f\n", averageTime);
}

void executeRoundRobin(PArray* array)
{
  float totalTime = 0.0f;
  float averageTime;
  float timePerProcess = 5;
  int run = 1;

  while (hasWaitingProcesses(array))
  {
    printf("-------------------\n");
    printf("RUN NUMBER: %d\n\n", run);

    for (int i = 0; i < NUM_PROCESSES; i++)
    {
      if (array->processes[i]->completed == false)
      {
        printf("\t-------------------\n");
        printf("\tProcess w/ ID: %d\n", array->processes[i]->id);
        printf("\tTotal time: %d\n", array->processes[i]->time);
        printf("\tPriority: %d\n", array->processes[i]->priority);

        array->processes[i]->time -= timePerProcess;
        
        if (array->processes[i]->time < 0)
          array->processes[i]->time = 0;
        
        printf("\tTime remaining: %d\n", array->processes[i]->time);

        totalTime += timePerProcess;
      }

      if (array->processes[i]->time <= 0 && array->processes[i]->completed == false)
      {
        array->processes[i]->completed = true;

        printf("\tProcess Complete!\n");
      }
    }

    run++;
  }

  printf("-----------------\n");
  printf("Time taken to execute queue: %f\n", totalTime);
}















