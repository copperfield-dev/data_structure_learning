public class HeapSort() {
    public static void sort(Comparable[] a) {
        int N = a.length;

        // build heap
        for (int k = N / 2; k >= 1; k--) {
            sink(a, k, N);
        }

        // sink sort
        while (N > 1) {
            exch(a, 1, N--);
            sink(a, 1, N);
        }
    }

    private void sink(Comparable[] a, int k, int N) {
        while (2 * k <= N) {
            int j = 2 * k;
            if (j < N && less(a[j], a[j + 1]))
                j++;
            if (!less(a[k], a[j]))
                break;
            exch(k, j);
            k = j;
        }
    }
}