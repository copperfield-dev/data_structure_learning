/* Stack implementation is a dynamically allocated array */
#define EmptyTOS (-1)
#define MinStackSize (5)

struct StackRecord {
  int capacity;
  int topOfStack;
  ElementType *array;
};

Stack CreateStack(int maxElements) {
  Stack S;

  if (maxElements < MinStackSize)
    Error("Stack size is too small");

  S = malloc(sizeof(struct StackRecord));
  if (S == NULL)
   FatalError("Out of space!!!");

  S->array = malloc(sizeof(ElementType) * maxElements);
  if (S->array == NULL)
    FatalError("Out of space!!!");
  S->capacity = maxElements;
  MakeEmpty(S);

  return S;
}

void DisposeStack(Stack S) {
  if (S != NULL) {
    free(S->array);
    free(S);
  }
}

int IsEmpty(Stack S) {
  return S->topOfStack == EmptyTOS;
}

void MakeEmpty(Stack S) {
  S->topOfStack = EmptyTOS;
}

void Push(ElementType X, Stack S) {
  if (IsFull(S))
    Error("Full Stack");
  else
    S->array[++S->topOfStack] = X;
}

ElementType Top(Stack S) {
  if (!IsEmpty(S))
    return S->array[S->topOfStack];
  Error("Empty Stack");
  return 0;      // Return value used to avoid waring
}

void Pop(Stack S) {
  if (IsEmpty(S)) 
    Error("Empty Stack");
  else
    S->topOfStack--;
}

ElementType TopAndPop(Stack S) {
  if (!IsEmpty(S))
    return S->array[S->topOfStack--];
  Error("Empty Stack");
  return 0;      // Return value used to avoid waring
}