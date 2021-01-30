import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
};

class FindAllTreePaths {
    private static void findPaths(TreeNode root, int sum, List<Integer> path, List<List<Integer>> allPaths) {
        if(root==null) {
            return;
        }
        path.add(root.val);
        if(root.val==sum && root.left==null && root.right==null) {
            allPaths.add(new ArrayList<Integer>(path));
        } else {
            findPaths(root.left, sum-root.val, path, allPaths);
            findPaths(root.right, sum-root.val, path, allPaths);
        }
        path.remove(path.size()-1);
    }
    public static List<List<Integer>> findPaths(TreeNode root, int sum) {
        List<List<Integer>> allPaths = new ArrayList<>();
        // TODO: Write your code here
        List<Integer> path = new ArrayList<Integer>();
        findPaths(root, sum, path, allPaths);
        return allPaths;
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(12);
        root.left = new TreeNode(7);
        root.right = new TreeNode(1);
        root.left.left = new TreeNode(4);
        root.right.left = new TreeNode(10);
        root.right.right = new TreeNode(5);
        int sum = 23;
        List<List<Integer>> result = FindAllTreePaths.findPaths(root, sum);
        System.out.println("Tree paths with sum " + sum + ": " + result);
    }
}


/*
https://leetcode.com/problems/path-sum-ii/
class Solution {
    private List<List<Integer>> result;
    private void findPaths(TreeNode root, int targetSum, List<Integer> path) {
        if(root==null) {
            return;
        }

        path.add(root.val);
        if(targetSum==root.val && root.left==null && root.right==null) {
            result.add(new ArrayList<Integer>(path));
        } else {
            findPaths(root.left, targetSum-root.val, path);
            findPaths(root.right, targetSum-root.val, path);
        }
        path.remove(path.size()-1);
    }
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<Integer> path = new ArrayList<Integer>();

        result = new ArrayList<List<Integer>>();
        findPaths(root, targetSum, path);

        return result;
    }
}
 */