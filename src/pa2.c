#include "queue.h"

#define DEBUG 1

int main()
{
  ProcessQueue* q = create();
  seed();

  fifo(q);
  
  print(q);

  return 0;
}
