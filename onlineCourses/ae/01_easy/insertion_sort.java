import java.util.*;

/*
https://www.interviewbit.com/tutorial/insertion-sort-algorithm/#
https://www.hackerearth.com/practice/algorithms/sorting/insertion-sort/tutorial/
*/

class Program {
  public static int[] insertionSort(int[] array) {
    // Write your code here.
    int i, j, key, N=array.length;

    for(i=1; i<N; i++) {
      key = array[i];
      for(j=i-1; j>=0 && array[j]>key; j--) {
        array[j+1] = array[j];
      }
      array[j+1] = key;
    }

    return array;
  }
}
