#ifndef CUTOFF
#define CUTOFF 3
#endif

void QuickSort(ElementType A[], int N) {
  QSort(A, 0, N - 1);
}

/* Return median of left, center, and right */
/* Order this and hide the pivot */
ElementType MedianOfThreePartitioning(ElementType A[],
  int left, int right) {
  int center = (left + right) / 2;

  if (A[left] > A[center])
    Swap(&A[left], &A[center]);
  if (A[left] > A[right])
    Swap(&A[left], &A[right]);
  if (A[center] > A[right])
    Swap(&A[center], &A[right]);

  /* Invariant: A[left] <= A[center] <= A[right] */

  Swap(&A[center], &A[right - 1]);   // Hide pivot
  return A[right - 1];               // Return pivot
}

void QSort(ElementType A[], int left, int right) {
  int i, j;
  ElementType pivot;

  if (left + CUTOFF <= right) {
    pivot = MedianOfThreePartitioning(A, left, right);
    i = left; j = right - 1;
    for( ; ; ) {
      while (A[++i] < pivot) {}
      while (A[--j] < pivot) {}
      if (i < j)
        Swap(&A[i], &A[j]);
      else
        break;
    }
    Swap(&A[i], &A[right - 1]);      // Restore pivot

    QSort(A, left, i - 1);
    QSort(A, i + 1, right);
  }
  else    // Do an insertion sort on the subarray
    InsertionSort(A + left, right - left + 1);
}