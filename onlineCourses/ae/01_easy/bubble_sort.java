import java.util.*;

/*
https://www.interviewbit.com/tutorial/bubble-sort/#bubble-sort
https://www.hackerearth.com/practice/algorithms/sorting/bubble-sort/tutorial/
*/

class Program {
  public static int[] bubbleSort(int[] array) {
    // Write your code here.
    boolean swapped;
    int i, j, N=array.length;

    for(i=0; i<N; i++) {
      swapped = false;
      for(j=0; j<N-1-i; j++) {
        if(array[j]>array[j+1]) {
          swap(j, j+1, array);
          swapped = true;
        }
      }
      if(!swapped) {
        break;
      }
    }
    return array;
  }

  private static void swap(int i, int j, int[] array) {
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
  }
}
