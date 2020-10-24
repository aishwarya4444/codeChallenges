import java.util.*;

class KthLargestNumberInStream {
    PriorityQueue<Integer> minHeap = new PriorityQueue<Integer>((n1, n2) -> {
        return n1 - n2;
    });
    final int K;

    public KthLargestNumberInStream(int[] nums, int k) {
        // TODO: Write your code here
        this.K = k;
        for(int num: nums) {
            this.add(num);
        }
    }

    public int add(int num) {
        // TODO: Write your code here
        this.minHeap.add(num);
        if(this.minHeap.size() > this.K) {
            this.minHeap.poll();
        }
        return this.minHeap.peek();
    }

    public static void main(String[] args) {
        int[] input = new int[] { 3, 1, 5, 12, 2, 11 };
        KthLargestNumberInStream kthLargestNumber = new KthLargestNumberInStream(input, 4);
        System.out.println("4th largest number is: " + kthLargestNumber.add(6));
        System.out.println("4th largest number is: " + kthLargestNumber.add(13));
        System.out.println("4th largest number is: " + kthLargestNumber.add(4));
    }
}