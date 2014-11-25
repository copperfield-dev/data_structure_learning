#include "stdlib.h"
#include <List.h>

struct Node {
  ElementType Element;
  Position next;
};

/* Return true if L is empty */
int IsEmpty(List L) {
  return L->next == NULL;
}

/* Return true if P is the last position in list L */
/* Parameter L is unused in this implementation */
int IsLast(Position P, List L) {
  return P->next == NULL;
}

/* Return Position of X in L; NULL if not found */
Position Find(ElementType X, List L) {
  Position P;

  P = L->Next;
  while(P != NULL && P->Element != X)
    P = P->next;

  return P;
}

/* Delete first occurrence of X from a list */
/* Assume use of a header node */
void Delete(ElementType X, List L) {
  Position P, tmpCell;

  P = FindPrevious(X, L);

  if (!IsLast(P, L)) {           // Assumption of header use
    tmpCell = P->next;           // X is found; delete it
    P->next = tmpCell->next;     // Bypass deleted cell
    free(tmpCell);
  }
}

/* If X is not found, then next field of returned */
/* Position is NULL*/
/* Assumes a header */
Position FindPrevious(ElementType X, List L) {
  Position P;

  P = L;
  while(P->next != NULL && P->next->Element != X)
    P = P->next;

  return P;
}

/* Insert (after legal position P */
/* Header implementation assumed */
/* Parameter L is unused in this implementation */
void Insert(ElementType X, List L, Position P) {
  Position tmpCell;

  tmpCell = malloc(sizeof(struct Node));
  if (tmpCell == NULL)
    FatalError("Out of space!!!");

  tmpCell->Element = X;
  tmpCell->next = P->next;
  P->next = tmpCell;
}

/* Correct DeleteList algorithm */
void DeleteList(List L) {
  Position P, tmp;

  P = List->next;  //Header assumed
  L->next = NULL;
  while(P != NULL) {
    tmp = P->next;
    free(P);
    P = tmp;
  }
}