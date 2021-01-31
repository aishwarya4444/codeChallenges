/*
https://leetcode.com/problems/find-k-pairs-with-smallest-sums/


// fast solution
class Solution {
    public List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        PriorityQueue<List<Integer>> maxHeap = new PriorityQueue<List<Integer>>((p1, p2) -> {
            return p2.get(0) + p2.get(1) - p1.get(0) - p1.get(1);
        });
        int i, j;

        for(i=0; i<nums1.length && i<k; i++) {
            for(j=0; j<nums2.length && j<k; j++) {
                List<Integer> tmp = new ArrayList<>();
                tmp.add(nums1[i]);
                tmp.add(nums2[j]);
                if(maxHeap.size() < k) {
                    maxHeap.add(tmp);
                } else if(nums1[i]+nums2[j] < maxHeap.peek().get(0)+maxHeap.peek().get(1)) {
                    maxHeap.poll();
                    maxHeap.add(tmp);
                }
            }
        }

        return new ArrayList<List<Integer>>(maxHeap);

    }
}


// slow solution
class Solution {
    public List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        PriorityQueue<List<Integer>> maxHeap = new PriorityQueue<List<Integer>>((p1, p2) -> {
            return p2.get(0) + p2.get(1) - p1.get(0) - p1.get(1);
        });
        int i, j;

        for(i=0; i<nums1.length && i<k; i++) {
            for(j=0; j<nums2.length && j<k; j++) {
                List<Integer> tmp = new ArrayList<>();
                tmp.add(nums1[i]);
                tmp.add(nums2[j]);
                maxHeap.add(tmp);
                if(maxHeap.size() > k) {
                    maxHeap.poll();
                }
            }
        }

        return new ArrayList<List<Integer>>(maxHeap);

    }
}
 */