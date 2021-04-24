import java.util.*;

class Program {
  public static boolean hasSingleCycle(int[] array) {
    // Write your code here.
    int visited=0, start=0;

    while(visited < array.length) {
      if(visited>0 && start==0) {
        return false;
      }
      visited++;
      start = getNext(start, array);
    }
    return start==0;
  }

  private static int getNext(int start, int[] array) {
    int next = start+array[start];

    while(next<0) {
      next += array.length;
    }
    next %= array.length;

    return next;
  }
}
