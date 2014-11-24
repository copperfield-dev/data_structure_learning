#include <List.h>

struct Node {
  ElementType Element;
  Position Next;
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
