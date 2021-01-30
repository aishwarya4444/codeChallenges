import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
};

class ReverseLevelOrderTraversal {
    public static List<List<Integer>> traverse(TreeNode root) {
        List<List<Integer>> result = new LinkedList<List<Integer>>();
        // TODO: Write your code here
        Queue<TreeNode> q = new LinkedList<>();

        if(root != null) {
            q.add(root);
        }

        while(!q.isEmpty()) {
            int N = q.size();
            List<Integer> res = new ArrayList<>();
            while(N > 0) {
                N--;
                root = q.poll();
                res.add(root.val);
                if(root.left != null) {
                    q.add(root.left);
                }
                if(root.right != null) {
                    q.add(root.right);
                }
            }
            result.add(0, res);
        }
        return result;
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(12);
        root.left = new TreeNode(7);
        root.right = new TreeNode(1);
        root.left.left = new TreeNode(9);
        root.right.left = new TreeNode(10);
        root.right.right = new TreeNode(5);
        List<List<Integer>> result = ReverseLevelOrderTraversal.traverse(root);
        System.out.println("Reverse level order traversal: " + result);
    }
}

/*
https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
class Solution {
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        int n;
        List<Integer> res;

        if(root!=null) {
            q.add(root);
        }

        while(q.size() > 0) {
            n = q.size();
            res = new ArrayList<Integer>();
            while(n > 0) {
                n--;
                root = q.poll();
                res.add(root.val);
                if(root.left!=null) {
                    q.add(root.left);
                }
                if(root.right!=null) {
                    q.add(root.right);
                }
            }
            result.add(0, res);
        }

        return result;
    }
}
*/