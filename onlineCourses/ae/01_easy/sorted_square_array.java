import java.util.*;

class Program {

  public int[] sortedSquaredArray(int[] array) {
    // Write your code here.
    int lb=0, ub=array.length-1, i=array.length-1;
    int[] result = new int[array.length];

    while(lb<=ub) {
      if(Math.abs(array[lb]) > Math.abs(array[ub])) {
        result[i] = array[lb]*array[lb];
        lb++;
      } else {
        result[i] = array[ub]*array[ub];
        ub--;
      }
      i--;
    }
    return result;
  }
}
