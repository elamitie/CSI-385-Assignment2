#include "queue.h"

ProcessQueue* create()
{
  ProcessQueue* queue = (ProcessQueue*)malloc(sizeof(ProcessQueue));
  queue->front = NULL;
  queue->rear = NULL;
  queue->count = 0;

  return queue;
}

void enqueue(ProcessQueue* queue, Process* process)
{
  struct node* n = (struct node*)malloc(sizeof(struct node));
  n->process = process;
  n->next = NULL;

  if (queue->front == NULL && queue->rear == NULL)
  {
    queue->front = queue->rear = n;
    return;
  }

  queue->rear->next = n;
  queue->rear = n;
  queue->count++;
}

void dequeue(ProcessQueue* queue)
{
  struct node* n = queue->front;
  if (queue->front == NULL)
  {
    printf("Queue Empty\n");
    return;
  }

  if (queue->front == queue->rear)
  {
    queue->front = queue->rear = NULL;
  }
  else
  {
    queue->front = queue->front->next;
  }

  queue->count--;
  free(n->process);
  free(n);
}

Process* front(ProcessQueue* queue)
{
  if (queue->front == NULL)
  {
    printf("Queue Empty\n");
    return NULL;
  }

  return queue->front->process;
}

Process* rear(ProcessQueue* queue)
{
  if (queue->front == NULL)
  {
    printf("Queue Empty\n");
    return NULL;
  }

  if (queue->rear == NULL)
  {
    printf("Error in Queue Construction: Rear NULL\n");
    return NULL;
  }

  return queue->rear->process;
}

void setFront(ProcessQueue* queue, Process* process)
{
  /* Temp */
}

void printIDs(ProcessQueue* queue)
{
  struct node* n = queue->front;
  while (n != NULL)
  {
    printf("Process w/ ID: %d\n", n->process->id);
    n = n->next;
  }
}

void print(ProcessQueue* queue)
{
  struct node* n = queue->front;
  while (n != NULL)
  {
    printf("--------------------\n");
    printf("Process w/ ID: %d\n", n->process->id);
    printf("Execution Time: %d\n", n->process->time);
    printf("Priority Number: %d\n", n->process->priority);
    n = n->next;
  }
}
