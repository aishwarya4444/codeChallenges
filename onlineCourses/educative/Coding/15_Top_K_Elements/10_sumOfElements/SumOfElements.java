import java.util.*;

class SumOfElements {

    public static int findSumOfElements(int[] nums, int k1, int k2) {
        // TODO: Write your code here
        PriorityQueue<Integer> maxHeap = new PriorityQueue<Integer>((n1, n2) -> n2-n1);
        int sum = 0;

        for(int num: nums) {
            maxHeap.add(num);
            if(maxHeap.size() > k2) {
                maxHeap.poll();
            }
        }

        maxHeap.poll();

        for(int i=k2-1; i>k1; i--) {
            sum += maxHeap.poll();
        }

        return sum;
    }

    public static void main(String[] args) {
        int result = SumOfElements.findSumOfElements(new int[] { 1, 3, 12, 5, 15, 11 }, 3, 6);
        System.out.println("Sum of all numbers between k1 and k2 smallest numbers: " + result);

        result = SumOfElements.findSumOfElements(new int[] { 3, 5, 8, 7 }, 1, 4);
        System.out.println("Sum of all numbers between k1 and k2 smallest numbers: " + result);
    }
}
