import java.util.*;

class Node {
    public int row;
    public int col;
    public int val;
    Node(int row, int col, int val) {
        this.row = row;
        this.col = col;
        this.val = val;
    }
}

class SmallestRange {

    public static int[] findSmallestRange(List<Integer[]> nums) {
        int row, col, val, R=nums.size(), C;
        int minNum, maxNum, start, end;
        PriorityQueue<Node> minHeap = new PriorityQueue<Node>((n1, n2) -> {
            return n1.val-n2.val;
        });

        maxNum = nums.get(0)[0];
        for(row=0; row<R; row++) {
            val = nums.get(row)[0];
            minHeap.add(new Node(row, 0, val));
            maxNum = Math.max(maxNum, val);
        }
        minNum = minHeap.peek().val;

        start = minNum;
        end = maxNum;
        while(minHeap.size() == R) {
            Node tmp = minHeap.poll();
            row = tmp.row;
            col = tmp.col;
            minNum = tmp.val;
            if(end-start > maxNum-minNum) {
                start = minNum;
                end = maxNum;
            }
            C = nums.get(row).length;
            if(col+1<C) {
                val = nums.get(row)[col+1];
                minHeap.add(new Node(row, col+1, val));
                maxNum = Math.max(maxNum, val);
            }
        }

        return new int[]{start, end};
    }

    public static void main(String[] args) {
        Integer[] l1 = new Integer[] { 1, 5, 8 };
        Integer[] l2 = new Integer[] { 4, 12 };
        Integer[] l3 = new Integer[] { 7, 8, 10 };
        List<Integer[]> lists = new ArrayList<Integer[]>();
        lists.add(l1);
        lists.add(l2);
        lists.add(l3);
        int[] result = SmallestRange.findSmallestRange(lists);
        System.out.print("Smallest range is: [" + result[0] + ", " + result[1] + "]");
    }
}

/*
https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/
class Node {
    public int row;
    public int col;
    Node(int row, int col) {
        this.row = row;
        this.col = col;
    }
}

class Solution {
    public int[] smallestRange(List<List<Integer>> nums) {
        int row, col, val, R=nums.size(), C;
        int minNum, maxNum, start, end;
        PriorityQueue<Node> minHeap = new PriorityQueue<Node>((n1, n2) -> {
            return nums.get(n1.row).get(n1.col)-nums.get(n2.row).get(n2.col);
        });

        val = nums.get(0).get(0);
        minNum = val;
        maxNum = val;
        for(row=0; row<R; row++) {
            val = nums.get(row).get(0);
            minHeap.add(new Node(row, 0));
            minNum = Math.min(minNum, val);
            maxNum = Math.max(maxNum, val);
        }

        start = minNum;
        end = maxNum;
        while(minHeap.size() == R) {
            Node tmp = minHeap.poll();
            row = tmp.row;
            col = tmp.col;
            minNum = nums.get(row).get(col);
            if(end-start > maxNum-minNum) {
                start = minNum;
                end = maxNum;
            }
            C = nums.get(row).size();
            if(col+1<C) {
                val = nums.get(row).get(col+1);
                minHeap.add(new Node(row, col+1));
                maxNum = Math.max(maxNum, val);
            }
        }

        return new int[]{start, end};
    }
}
 */