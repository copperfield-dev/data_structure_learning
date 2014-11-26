#include "stdlib.h"
#include "Stack.h"

/* Stack implementation is a linked list with a header */
struct Node {
  ElementType element;
  PtrToNode next;
};

int IsEmpty(Stack S) {
  return S->next == NULL;
}

Stack CreateStack(void) {
  Stack S;

  S = malloc(sizeof(struct Node));
  if (S == NULL)
    FatalError("Out of space!!!");
  S->next == NULL;
  MakeEmpty(S);
  return S;
}

void MakeEmpty(Stack S) {
  if (S == NULL)
    Error("Must use CreateStack first");
  else
    while (!IsEmpty(S))
      Pop(S);
}

void Push(ElementType X, Stack S) {
  PtrToNode tmpCell;

  tmpCell = malloc(sizeof(struct Node));
  if (tmpCell == NULL)
    FatalError("Out of space!!!");
  else {
    tmpCell->element = X;
    tmpCell->next = S->next;
    S->next = tmpCell;
  }
}

ElementType Top(Stack S) {
  if (!IsEmpty(S))
    return S->next->element;
  Error("Empty Stack");
  return 0;        // Return value used to avoid waring
}

void Pop(Stack S) {
  PtrToNode firstCell;

  if (IsEmpty(S)) 
    Error("Empty Stack");
  else {
    firstCell = S->next;
    S->next = S->next->next;
    free(firstCell);
  }
}