#ifndef QUEUE_H
#define QUEUE_H

#include "process.h"

/* Used internally no real reason to typedef */
struct node
{
  Process* process;
  struct node* next;
};

typedef struct pqueue
{
  struct node* front;
  struct node* rear; 
  int count;
} ProcessQueue;

ProcessQueue* create();

/* Enqueue process */
void enqueue(ProcessQueue* queue, Process* process);

/* Dequeue process */
void dequeue(ProcessQueue* queue);

/* Get the front process */
Process* front(ProcessQueue* queue);

/* Get the rear process */
Process* rear(ProcessQueue* queue);

/* Set the frong process */
void setFront(ProcessQueue* queue, Process* process);

/* Print just the PIDS */
void printIDs(ProcessQueue* queue);

/* Print everything */
void print(ProcessQueue* queue);

#endif
