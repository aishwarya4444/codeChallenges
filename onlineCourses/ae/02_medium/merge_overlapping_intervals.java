import java.util.*;

class Program {

  public int[][] mergeOverlappingIntervals(int[][] intervals) {
    // Write your code here.
    TreeMap<Integer, Integer> count = new TreeMap<>();
    List<int[]> merged = new ArrayList<>();
    int sum=0, start=0, end, key, val;

    for(int[] interval: intervals) {
      start = interval[0];
      end = interval[1];
      count.put(start, count.getOrDefault(start, 0)+1);
      count.put(end, count.getOrDefault(end, 0)-1);
    }

    for(Map.Entry<Integer, Integer> entry: count.entrySet()) {
      key = entry.getKey();
      val = entry.getValue();
      if(sum==0) {
        start = key;
      }
      sum += val;
      if(sum==0) {
        end = key;
        merged.add(new int[]{start, end});
      }
    }

    return merged.toArray(new int[merged.size()][]);
  }
}


/*
import java.util.*;

class Program {

  public int[][] mergeOverlappingIntervals(int[][] intervals) {
    // Write your code here.
		int[][] sortedIntervals = intervals.clone();
		// Arrays.sort(sortedIntervals, (a, b) -> Integer.compare(a[0], b[0]));
		Arrays.sort(sortedIntervals, (a, b) -> {
			return a[0]-b[0];
		});

		List<int[]> merged = new ArrayList<int[]>();
		int start = sortedIntervals[0][0];
		int end = sortedIntervals[0][1];

		for(int[] interval: sortedIntervals) {
			if(end>=interval[0]) {
				end = Math.max(end, interval[1]);
			} else {
				merged.add(new int[]{start, end});
				start = interval[0];
				end = interval[1];
			}
		}
		merged.add(new int[]{start, end});

    return merged.toArray(new int[merged.size()][]);
  }
}
 */