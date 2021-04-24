import java.util.*;

class Program {
  public static int quickselect(int[] array, int k) {
    // Write your code here.
    Queue<Integer> maxh = new PriorityQueue<Integer>((n1, n2) -> {
      return n2-n1;
    });

    for(int num: array) {
      maxh.add(num);
      if(maxh.size() > k) {
        maxh.poll();
      }
    }

    return maxh.peek();
  }
}
