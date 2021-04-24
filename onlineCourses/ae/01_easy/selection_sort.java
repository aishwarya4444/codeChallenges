import java.util.*;

/*
https://www.hackerearth.com/practice/algorithms/sorting/selection-sort/tutorial/
https://www.interviewbit.com/tutorial/selection-sort/#selection-sort
*/

class Program {
  public static int[] selectionSort(int[] array) {
    // Write your code here.
    int i, minIdx, N=array.length;

    for(i=0; i<N; i++) {
      minIdx = findMinIdx(i, array);
      if(i != minIdx) {
        swap(i, minIdx, array);
      }
    }

    return array;
  }

  private static int findMinIdx(int start, int[] array) {
    int i, minIdx=start, N=array.length;

    for(i=start+1; i<N; i++) {
      if(array[i] < array[minIdx]) {
        minIdx = i;
      }
    }

    return minIdx;
  }

  private static void swap(int i, int j, int[] array) {
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
  }
}
