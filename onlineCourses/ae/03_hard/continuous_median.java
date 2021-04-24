import java.util.*;

// Do not edit the class below except for
// the insert method. Feel free to add new
// properties and methods to the class.
class Program {
  static class ContinuousMedianHandler {
    double median = 0;
    Queue<Integer> maxHeap = new PriorityQueue<Integer>((n1, n2) -> {
      return n2 - n1;
    });
    Queue<Integer> minHeap = new PriorityQueue<Integer>((n1, n2) -> {
      return n1 - n2;
    });

    public void insert(int number) {
      // Write your code here.
      maxHeap.add(number);
      minHeap.add(maxHeap.poll());

      if(maxHeap.size() < minHeap.size()) {
        maxHeap.add(minHeap.poll());
        median = maxHeap.peek();
      } else {
        median = (maxHeap.peek() + minHeap.peek()) / 2.0;
      }
    }

    public double getMedian() {
      return median;
    }
  }
}
