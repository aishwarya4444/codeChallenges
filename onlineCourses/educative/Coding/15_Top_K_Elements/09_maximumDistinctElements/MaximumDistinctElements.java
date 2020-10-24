import java.util.*;

class MaximumDistinctElements {

    public static int findMaximumDistinctElements(int[] nums, int k) {
        // TODO: Write your code here
        int val, count, distinct=0;
        Map<Integer, Integer> freq = new HashMap<>();
        PriorityQueue<Map.Entry<Integer, Integer>> minHeap = new PriorityQueue<Map.Entry<Integer, Integer>>((e1, e2) -> {
            return e1.getValue()-e2.getValue();
        });

        for(int num: nums) {
            freq.put(num, freq.getOrDefault(num, 0)+1);
        }

        minHeap.addAll(freq.entrySet());

        while(minHeap.size() > 0) {
            Map.Entry<Integer, Integer> entry = minHeap.poll();
            val = entry.getKey();
            count = entry.getValue();
            if(count != 1) {
                k = k - (count-1);
            }
            if(k >= 0) {
                distinct++;
            } else {
                break;
            }
        }

        if(k>0) {
            distinct -= k;
        }
        return distinct;
    }

    public static void main(String[] args) {
        int result = MaximumDistinctElements.findMaximumDistinctElements(new int[] { 7, 3, 5, 8, 5, 3, 3 }, 2);
        System.out.println("Maximum distinct numbers after removing K numbers: " + result);

        result = MaximumDistinctElements.findMaximumDistinctElements(new int[] { 3, 5, 12, 11, 12 }, 3);
        System.out.println("Maximum distinct numbers after removing K numbers: " + result);

        result = MaximumDistinctElements.findMaximumDistinctElements(new int[] { 1, 2, 3, 3, 3, 3, 4, 4, 5, 5, 5 }, 2);
        System.out.println("Maximum distinct numbers after removing K numbers: " + result);
    }
}