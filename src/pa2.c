#include "queue.h"

#define NUMBER_PROCESSES 10
#define DEBUG 1

int main()
{
  ProcessQueue* q = create();
  seed();

  for (int i = 0; i < NUMBER_PROCESSES; i++)
  {
    Process* p;
    if (i - 1 < 0)
    {
      p = forkSim(NULL);
      enqueue(q, p);
    }
    else
    {
      p = forkSim(rear(q));
      enqueue(q, p);
    }
  }

  print(q);

  return 0;
}
