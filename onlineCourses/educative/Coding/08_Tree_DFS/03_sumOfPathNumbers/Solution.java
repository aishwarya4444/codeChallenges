import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
};

class SumOfPathNumbers {
    private static int sum;

    private static void findSum(TreeNode root, int num) {
        if(root==null) {
            return;
        }

        num = num*10 + root.val;
        if(root.left==null && root.right==null) {
            sum += num;
            return;
        }
        findSum(root.left, num);
        findSum(root.right, num);
    }

    public static int findSumOfPathNumbers(TreeNode root) {
        // TODO: Write your code here
        sum = 0;
        findSum(root, 0);
        return sum;
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(0);
        root.right = new TreeNode(1);
        root.left.left = new TreeNode(1);
        root.right.left = new TreeNode(6);
        root.right.right = new TreeNode(5);
        System.out.println("Total Sum of Path Numbers: " + SumOfPathNumbers.findSumOfPathNumbers(root));
    }
}

/*
https://leetcode.com/problems/sum-root-to-leaf-numbers/
class Solution {
    private int sum;

    private void findSum(TreeNode root, int num) {
        if(root==null) {
            return;
        }

        num = num*10 + root.val;
        if(root.left==null && root.right==null) {
            sum += num;
            return;
        }
        findSum(root.left, num);
        findSum(root.right, num);
    }

    public int sumNumbers(TreeNode root) {
        sum = 0;
        findSum(root, 0);
        return sum;
    }
}
 */