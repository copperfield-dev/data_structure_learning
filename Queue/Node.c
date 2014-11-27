#include "stdlib.h"
#include "Queue.h"

/* Queue implementation is a dynamically allocated array */
#define MinQueueSize (5)

struct QueueRecord {
  int capacity;
  int front;
  int rear;
  int size;
  ElementType *array;
};

int IsEmpty(Queue Q) {
  return Q->size == 0;
}

void MakeEmpty(Queue Q) {
  Q->size = 0;
  Q->front = 1;
  Q->rear = 0;
}

static int Succ(int value, Queue Q) {
  if(++value == Q->capacity)
    value = 0;
  return value;
}

void Enqueue(ElementType X, Queue Q) {
  if (IsFull(Q))
    Error("Full Queue");
  else {
    Q->size++;
    Q->rear = Succ(Q->rear, Q);
    Q->array[Q->rear] = X;
  }
}