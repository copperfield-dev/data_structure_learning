void InsertionSort(ElementType A[], int N) {
  int p;

  ElementType tmp;
  for (p = 1; p < N; p++) {
    tmp = A[p];
    for (int i = p; i > 0 && A[i - 1] > tmp; i--) 
      A[i] = A[i - 1];
    A[i] = tmp;
  }
}