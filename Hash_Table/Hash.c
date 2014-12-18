typedef unsigned int Index;

Index Hash_1(const char *key, int tableSize) {
  unsigned int hashVal = 0;

  while (*key != '\0')
    hashVal += *key++;

  return hashVal % tableSize;
}

Index Hash_2(const char *key, int tableSize) {
  return (key[0] + 27 * key[1] + 729 * key[2]) 
            % tableSize;
}

Index Hash_3(const char *key, int tableSize) {
  unsigned int hashVal = 0;

  while (*key != '\0')
    hashVal = (hashVal << 5) + *key++;

  return hashVal % tableSize;
}