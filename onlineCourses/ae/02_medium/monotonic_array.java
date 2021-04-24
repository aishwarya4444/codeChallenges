import java.util.*;

class Program {
  public static boolean isMonotonic(int[] array) {
    // Write your code here.
    int n=1, N=array.length;

    while(n<N && array[n-1]==array[n]) {
      n++;
    }

    if(n==N || N<2) {
      return true;
    }

    if(array[n-1]<array[n]) {
      // check increasing
      while(n<N) {
        if(array[n-1]>array[n]) {
          return false;
        }
        n++;
      }
    } else {
      // check decreasing
      while(n<N) {
        if(array[n-1]<array[n]) {
          return false;
        }
        n++;
      }
    }
    return true;
  }
}
