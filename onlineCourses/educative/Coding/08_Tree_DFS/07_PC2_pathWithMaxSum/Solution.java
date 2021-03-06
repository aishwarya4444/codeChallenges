class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
};

class MaximumPathSum {
    private static int maxSum;

    private static int findMaxSum(TreeNode root) {
        if(root==null) {
            return 0;
        }

        // by comparing with 0
        // we limit nodes to non leaf nodes
        // i did this mistalke in interview
        // this is how it differs from diameter
        int lSum = Math.max(0, findMaxSum(root.left));
        int rSum = Math.max(0, findMaxSum(root.right));

        maxSum = Math.max(maxSum, root.val+lSum+rSum);

        return root.val + Math.max(lSum, rSum);
    }

    public static int findMaximumPathSum(TreeNode root) {
        // TODO: Write your code here
        maxSum = Integer.MIN_VALUE;
        findMaxSum(root);
        return maxSum;
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        System.out.println("Maximum Path Sum: " + MaximumPathSum.findMaximumPathSum(root));
        root.left.left = new TreeNode(1);
        root.left.right = new TreeNode(3);
        root.right.left = new TreeNode(5);
        root.right.right = new TreeNode(6);
        root.right.left.left = new TreeNode(7);
        root.right.left.right = new TreeNode(8);
        root.right.right.left = new TreeNode(9);
        System.out.println("Maximum Path Sum: " + MaximumPathSum.findMaximumPathSum(root));
        root = new TreeNode(-1);
        root.left = new TreeNode(-3);
        System.out.println("Maximum Path Sum: " + MaximumPathSum.findMaximumPathSum(root));
    }
}

/*
https://leetcode.com/problems/binary-tree-maximum-path-sum/
class Solution {
    private int maxSum;

    private int findMaxSum(TreeNode root) {
        if(root==null) {
            return 0;
        }

        int lSum = Math.max(0, findMaxSum(root.left));
        int rSum = Math.max(0, findMaxSum(root.right));

        maxSum = Math.max(maxSum, root.val+lSum+rSum);

        return root.val + Math.max(lSum, rSum);
    }
    public int maxPathSum(TreeNode root) {
        maxSum = Integer.MIN_VALUE;
        findMaxSum(root);
        return maxSum;
    }
}
 */