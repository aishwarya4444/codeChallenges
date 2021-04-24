import java.util.*;

class Program {

  public int laptopRentals(ArrayList<ArrayList<Integer>> times) {
    // Write your code here.
    Map<Integer, Integer> freq = new TreeMap<>();
    int sum=0, maxSum=0, start, end;

    for(ArrayList<Integer> time: times) {
      start = time.get(0);
      end = time.get(1);
      freq.put(start, freq.getOrDefault(start, 0)+1);
      freq.put(end, freq.getOrDefault(end, 0)-1);
    }

    for(Map.Entry<Integer, Integer> entry: freq.entrySet()) {
      sum += entry.getValue();
      maxSum = Math.max(sum, maxSum);
    }

    return maxSum;
  }
}
