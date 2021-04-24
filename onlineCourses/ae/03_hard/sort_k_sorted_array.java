import java.util.*;

class Program {

  public int[] sortKSortedArray(int[] array, int k) {
    // Write your code here.
    int lb, ub, N=array.length;
    Queue<Integer> minHeap = new PriorityQueue<Integer>((n1, n2) -> {
      return n1 - n2;
    });

    for(ub=0; ub<Math.min(1+k, N); ub++) {
      minHeap.add(array[ub]);
    }

    for(lb=0; ub<N; lb++, ub++) {
      array[lb] = minHeap.poll();
      minHeap.add(array[ub]);
    }

    while(minHeap.size() > 0) {
      array[lb] = minHeap.poll();
      lb++;
    }

    return array;
  }
}
