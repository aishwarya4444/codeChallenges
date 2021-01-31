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

class KthSmallestInMSortedArrays {

    public static int findKthSmallest(List<Integer[]> lists, int k) {
        PriorityQueue<Node> minHeap = new PriorityQueue<Node>((n1, n2) -> {
            return n1.val - n2.val;
        });
        int val=lists.get(0)[0], row, col, R=lists.size();

        for(row=0; row<R; row++) {
            minHeap.add(new Node(row, 0, lists.get(row)[0]));
        }

        while(k > 0) {
            Node tmp = minHeap.poll();
            k--;
            row = tmp.row;
            col = tmp.col;
            val = tmp.val;
            if(col+1 < lists.get(row).length) {
                minHeap.add(new Node(row, col+1, lists.get(row)[col+1]));
            }
        }

        return val;
    }

    public static void main(String[] args) {
        Integer[] l1 = new Integer[] { 2, 6, 8 };
        Integer[] l2 = new Integer[] { 3, 6, 7 };
        Integer[] l3 = new Integer[] { 1, 3, 4 };
        List<Integer[]> lists = new ArrayList<Integer[]>();
        lists.add(l1);
        lists.add(l2);
        lists.add(l3);
        int result = KthSmallestInMSortedArrays.findKthSmallest(lists, 5);
        System.out.print("Kth smallest number is: " + result);
    }
}


/*
https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
public class Node {
    public int row;
    public int col;
    public int val;
    Node(int row, int col, int val) {
        this.row = row;
        this.col = col;
        this.val = val;
    }
}

class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        PriorityQueue<Node> minHeap = new PriorityQueue<Node>((n1, n2) -> {
            return n1.val - n2.val;
        });
        int val=matrix[0][0], row, col, N=matrix.length;

        for(row=0; row<N; row++) {
            minHeap.add(new Node(row, 0, matrix[row][0]));
        }

        while(k > 0) {
            Node tmp = minHeap.poll();
            k--;
            row = tmp.row;
            col = tmp.col;
            val = tmp.val;
            if(col+1 < N) {
                minHeap.add(new Node(row, col+1, matrix[row][col+1]));
            }
        }

        return val;
    }
}
 */