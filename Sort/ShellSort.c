void ShellSort(ElementType A[], int N) {
  int increment;
  ElementType tmp;

  for(increment = N / 2; increment > 0; increment /= 2)
    for (int i = increment; i < N; i++) {
      tmp = A[i];
      for (int j = i; j >= increment; j -= increment)
        if (tmp < A[j - increment])
          A[j] = A[j - increment];
        else
          break;
      A[j] = tmp;
    }
}