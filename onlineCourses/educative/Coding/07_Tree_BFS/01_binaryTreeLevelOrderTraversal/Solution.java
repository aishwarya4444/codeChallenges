import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
};

class LevelOrderTraversal {
    public static List<List<Integer>> traverse(TreeNode root) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        // TODO: Write your code here
        Queue<TreeNode> q = new LinkedList<>();
        if(root != null) {
            q.add(root);
        }

        while(q.size() > 0) {
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
            result.add(res);
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
        List<List<Integer>> result = LevelOrderTraversal.traverse(root);
        System.out.println("Level order traversal: " + result);
    }
}

/*
https://leetcode.com/problems/binary-tree-level-order-traversal/
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        int n;

        if(root!=null) {
            q.add(root);
        }

        while(q.size()>0) {
            n = q.size();
            List<Integer> res = new ArrayList<Integer>();
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
            result.add(res);
        }

        return result;
    }
}
*/