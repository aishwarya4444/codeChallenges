import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
};

class ZigzagTraversal {
    public static List<List<Integer>> traverse(TreeNode root) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        // TODO: Write your code here
        Stack<TreeNode> s1 = new Stack<>();
        Stack<TreeNode> s2 = new Stack<>();
        List<Integer> res = new ArrayList<>();

        if(root != null) {
            s1.push(root);
        }

        while(!s1.isEmpty() || !s2.isEmpty()) {
            while(!s1.isEmpty()) {
                root = s1.pop();
                res.add(root.val);
                if(root.left != null) {
                    s2.push(root.left);
                }
                if(root.right != null) {
                    s2.push(root.right);
                }
            }
            result.add(res);
            res = new ArrayList<>();

            while(!s2.isEmpty()) {
                root = s2.pop();
                res.add(root.val);
                if(root.right != null) {
                    s1.push(root.right);
                }
                if(root.left != null) {
                    s1.push(root.left);
                }
            }
            result.add(res);
            res = new ArrayList<>();
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
        root.right.left.left = new TreeNode(20);
        root.right.left.right = new TreeNode(17);
        List<List<Integer>> result = ZigzagTraversal.traverse(root);
        System.out.println("Zigzag traversal: " + result);
    }
}


/*
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        List<Integer> res;
        Stack<TreeNode> s1 = new Stack<TreeNode>();
        Stack<TreeNode> s2 = new Stack<TreeNode>();

        if(root!=null) {
            s1.push(root);
        }

        while(s1.size()>0) {
            res = new ArrayList<Integer>();
            while(s1.size()>0) {
                root = s1.pop();
                res.add(root.val);
                if(root.left!=null) {
                    s2.push(root.left);
                }
                if(root.right!=null) {
                    s2.push(root.right);
                }
            }
            result.add(res);

            res = new ArrayList<Integer>();
            while(s2.size()>0) {
                root = s2.pop();
                res.add(root.val);
                if(root.right!=null) {
                    s1.push(root.right);
                }
                if(root.left!=null) {
                    s1.push(root.left);
                }
            }
            if(res.size()>0) {
                result.add(res);
            }
        }

        return result;

    }
}
*/