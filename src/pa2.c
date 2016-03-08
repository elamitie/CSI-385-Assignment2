#include "array.h"
#include <string.h>

#define DEBUG 1

int main(int argc, char** argv)
{
  PArray* array = create();
  seed();

  if (argc > 1)
  {
    if (strcmp(argv[1], "fifo") == 0)
    {
      fifo(array);
      execute(array);
    }
    else if (strcmp(argv[1], "shortestTime") == 0)
    {
      // Initialize the array, fifo is fine here
      fifo(array);
      shortestTime(array);
      execute(array);
    }
    else if (strcmp(argv[1], "priority") == 0)
    {
      // Initialize the array, fifo is fine here
      fifo(array);
      priority(array);
      execute(array);
    }
    else if (strcmp(argv[1], "fifoRoundRobin") == 0)
    {
      fifo(array);
      executeRoundRobin(array);
    }
    else if (strcmp(argv[1], "priorityRoundRobin") == 0)
    {
      // Initialize the array, fifo is fine here
      fifo(array);
      priority(array);
      executeRoundRobin(array);
    }
  }
  else
  {
    fifo(array);
    execute(array);
  }

  return 0;
}
