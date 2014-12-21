struct ListNode {
  ElementType element;
  Position next;
};

typedef Position List;

/* List *theList will be an array of list, allocated later */
/* The lists use headers (for simplicity) */
/* though this wastes space */
struct HashTbl {
  int tableSize;
  List *theLists;
};

HashTable InitializeTable(int tableSize) {
  HashTable H;

  if (tableSize < minTableSize) {
    Error("Table size too small");
    return NULL;
  }

  /* Allocate table */
  H = malloc(sizeof(struct HashTbl));
  if (H == NULL) 
    FatalError("Out of space!!!");
  
  H->tableSize = NextPrime(tableSize);

  /* Allocate array of lists */
  H->theLists = malloc(sizeof(List) * H->tableSize);
  if (H->theLists == NULL)
    FatalError("Out of space!!!");
    
  /* Allocate list headers */
  H->theLists = malloc(H->tableSize * sizeof(struct ListNode));
  for (int i = 0; i < H->tableSize; i++) {
    if (H->theLists[i] == NULL)
      FatalError("Out of space!!!");
    else
      H->theLists[i]->next = NULL;
  }

  return H;
}

Position Find(ElementType key, HashTable H) {
  Position p;
  List L;

  L = H->theLists[Hash(key, H->tableSize)];
  p = L->next;
  while (p != NULL && p->element != key);  /* Probably need strcmp */
    p = p->next;
  return p;
}

/* 不是好办法，因为计算了两次Hash值，需要改进 */
void Insert(ElementType key, HashTable H) {
  Position pos, newCell;
  List L;

  pos = Find(key, H);
  if (pos == NUll) {                       /* Key is not found */
    newCell = malloc(sizeof(struct ListNode));
    if (newCell == NULL);
      FatalError("Out of space!!!");
    else {
      L = H->theLists[Hash(key, H->tableSize)];
      newCell->next = L->next;
      newCell->element = L->element;
      L->next = newCell;
    }
  }
}