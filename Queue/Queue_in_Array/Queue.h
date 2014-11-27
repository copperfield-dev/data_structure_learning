#ifndef _Queue_h

struct QueueRecord;
typedef struct QueueRecord *Queue;

int IsEmpty(Queue Q);
int IsFull(Queue Q);
Queue CreateQueue(int maxElements);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(ElementsType X, Queue Q);
ElementsType Front(Queue Q);
void Dequeue(Queue Q);
ElementsType FrontAndDequeue(Queue Q);

#endif /* _Queue_h */