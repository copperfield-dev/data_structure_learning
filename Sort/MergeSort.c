void MSort(ElementType A[], ElementType tmpArray[],
  int left, int right) {
  int center;

  if (left < right) {
    center = (left + right) / 2;
    MSort(A, tmpArray, left, center);
    MSort(A, tmpArray, center + 1, right);
    Merge(A, tmpArray, left, center + 1, right);
  }
}

void MergeSort(ElementType A[], int N) {
  ElementType *tmpArray;

  tmpArray = malloc(N * sizeof(ElementType));
  if (tmpArray != NULL) {
    MSort(A, tmpArray, 0, N - 1);
    free(tmpArray);
  }
  else
    FatalError("No space for tmp array!!!");
}

void Merge(ElementType A[], ElementType tmpArray[],
  int leftStart, int rightStart, int rightEnd) {
  int leftEnd, numOfElements, tmpPosition;

  leftEnd = rightStart - 1;
  tmpPosition = leftStart;
  numOfElements = rightEnd - leftStart + 1;

  /* main loop */
  while (leftStart <= leftEnd && rightStart <= rightEnd)
    if (A[leftStart] <= A[rightStart])
      tmpArray[tmpPosition++] = A[leftStart++];
    else
      tmpArray[tmpPosition++] = B[rightStart++];
  
  /* Copy rest of first half */ 
  while (leftStart <= leftEnd) 
    tmpArray[tmpPosition++] = A[leftStart++];
  /* Copy rest of second half */
  while (rightStart <= rightEnd)
    tmpArray[tmpPosition++] = A[rightStart++];

  /* Copy tmpArray back */
  for (int i = 0; i < numOfElements; i++) {
    A[i] = tmpArray[i];
  }
}