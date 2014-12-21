enum KindOfEntry {Legitimate, Empty, Deleted};

struct HashEntry {
  ElementType element;
  enum KindOfEntry info;
};

typedef struct HashEntry Cell;

/* Cell *theList will be an array of */
/* HashEntry cells, allocated later */
struct HashTbl {
  int tableSize;
  Cell *theCells;
};

HashTable InitializeTable(int tableSize) {
  HashTable H;

  if (tableSize < MinTableSize) {
    Error("Table size too small");
    return NULL;
  }

  /* Allocate table */
  H = malloc(sizeof(struct HashTbl))；
  if (H == NULL) 
    FatalError("Out of space!!!");

  H->tableSize = NextPrime(tableSize);

  /* Allocate array of Cells */
  H->theCells = malloc(sizeof(Cell) * H->tableSize);
  if (H->theCells == NULL)
    FatalError("Out of space!!!");

  for (int i = 0; i < H->tableSize; i++) {
    H->theCells[i].info = Empty;
  }
}

Position Find(ElementType key, HashTable H) {
  Position currentPos;
  int collisionNum;

  collisionNum = 0;
  currentPos = Hash(key, H->tableSize);
  while (H->theCells[currentPos].info != Empty &&
         H->theCells[currentPos].element != key) {  /* Probably need strcmp!! */
    currentPos += 2 * ++collisionNum - 1;
    if (currentPos >= H->tableSize)
      currentPos -= H->tableSize;
  }
  return currentPos;
}

void Insert(ElementType key, HashTable H) {
  Position pos;

  pos = Find(key, H);
  if (H->theCells[pos].info != Legitimate) {
    /* OK to insert here */
    H->theCells[pos].info = Legitimate;
    H->theCells[pos].element = key;   /* Probably need strcpy!! */
  }
}

HashTable ReHash(HashTable H) {
  int oldSize;
  Cell *oldCells;

  oldCells = H->theCells;
  oldSize = H->tableSize;

  /* Get a new, empty table */
  H = InitializeTable(2 * oldSize);

  /* Scan through old table, reinserting into new */
  for (int i = 0; i < oldSize; i++) {
    if (oldCells[i].info == Legitimate)
      Insert(oldCells[i].element, H);
    }
  }

  free(oldCells);

  return H;
}