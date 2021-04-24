import java.util.*;

/*
https://www.interviewbit.com/tutorial/quicksort-algorithm/
https://www.hackerearth.com/practice/algorithms/sorting/quick-sort/tutorial/
https://www.geeksforgeeks.org/quicksort-using-random-pivoting/
*/

class Program {
  public static int[] quickSort(int[] array) {
    // Write your code here.
    qsort(0, array.length-1, array);
    return array;
  }

  private static void qsort(int start, int end, int[] array) {
    if(start < end) {
      int pivotIdx = partition(start, end, array);
      qsort(start, pivotIdx-1, array);
      qsort(pivotIdx+1, end, array);
    }
  }

  private static int partition(int start, int end, int[] array) {
    /* use below function call for randomized quick sort */
    // moveRandomNumberToEnd(start, end, array);

    int pivot = array[end];
    int i = start, j;

    for(j=start; j<end; j++) {
      if(array[j] <= pivot) {
        swap(i, j, array);
        i++;
      }
    }

    swap(i, end, array);

    return i;
  }

  private static void swap(int i, int j, int[] array) {
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
  }

  private static void moveRandomNumberToEnd(int start, int end, int[] array) {
    Random rand = new Random();
    int pivotIdx = rand.nextInt(end-start) + start;

    swap(pivotIdx, end, array);
  }
}
