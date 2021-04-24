import java.util.*;

class Program {
  public static int[] heapSort(int[] array) {
    // Write your code here.
    int n, N = array.length;

    buildMaxHeap(array, N);
    for(n=N-1; n>0; n--) {
      movePeakToEnd(0, n, array);
    }
    return array;
  }

  private static void buildMaxHeap(int[] array, int N) {
    for(int i=N/2-1; i>=0; i--) {
      siftDown(i, N-1, array);
    }
  }

  private static void siftDown(int i, int last, int[] array) {
    int large=i, left=2*i+1, right=2*i+2;

    if(left<=last && array[large]<array[left]) {
      large = left;
    }

    if(right<=last && array[large]<array[right]) {
      large = right;
    }

    if(large!=i) {
      swap(i, large, array);
      siftDown(large, last, array);
    }
  }

  private static void movePeakToEnd(int peak, int end, int[] array) {
    swap(peak, end, array);
    siftDown(peak, end-1, array);
  }

  private static void swap(int i, int j, int[] array) {
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
  }
}
