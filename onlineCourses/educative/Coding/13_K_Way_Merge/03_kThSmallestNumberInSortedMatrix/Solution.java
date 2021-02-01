// good question
// can be solved using binary search and heap

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
        Queue<Node> minHeap = new PriorityQueue<Node>((n1, n2) -> {
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

/*
https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        int row, col, R=matrix.length, C=matrix[0].length;
        int start, mid, end, count;

        start = matrix[0][0];
        end = matrix[R-1][C-1];

        while(start < end) {
            mid = start + (end-start)/2;

            count = 0;
            row = 0;
            col = C-1;
            while(row<R && col>=0) {
                if(matrix[row][col]<=mid) {
                    row++;
                    count += col+1;
                } else {
                    col--;
                }
            }

            if(count>=k) {
                end = mid;
            } else {
                start = mid+1;
            }
        }

        return start;
    }
}
 */





/*
https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/
class Solution {
    public int findKthNumber(int m, int n, int k) {
        int r, mid, count, start, end;

        start = 1;
        end = m*n;

        while(start < end) {
            mid = start + (end-start)/2;
            count = 0;
            for(r=1; r<=m; r++) {
                count += Math.min(mid/r , n);
            }
            if(count>=k) {
                end = mid;
            } else {
                start = mid+1;
            }
        }

        return start;
    }
}
 */