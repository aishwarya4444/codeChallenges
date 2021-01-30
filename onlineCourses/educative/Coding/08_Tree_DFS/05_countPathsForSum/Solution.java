import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
};

class CountAllPathSum {
    public static int countPaths(TreeNode root, int S) {
        // TODO: Write your code here
        return -1;
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(12);
        root.left = new TreeNode(7);
        root.right = new TreeNode(1);
        root.left.left = new TreeNode(4);
        root.right.left = new TreeNode(10);
        root.right.right = new TreeNode(5);
        System.out.println("Tree has path: " + CountAllPathSum.countPaths(root, 11));
    }
}

/*
https://leetcode.com/problems/path-sum-iii/
class Solution {
    private int count;
    private void countSum(TreeNode root, int sum, List<Integer> path) {
        if(root==null) {
            return;
        }

        path.add(root.val);
        for(int i=path.size()-1, total=0; i>=0; i--) {
            total += path.get(i);
            if(total==sum) {
                count++;
            }
        }

        countSum(root.left, sum, path);
        countSum(root.right, sum, path);

        path.remove(path.size()-1);
    }
    public int pathSum(TreeNode root, int sum) {
        List<Integer> path = new ArrayList<Integer>();

        count=0;
        countSum(root, sum, path);

        return count;
    }
}
 */