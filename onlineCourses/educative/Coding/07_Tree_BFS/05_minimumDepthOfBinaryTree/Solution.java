import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
};

class MinimumBinaryTreeDepth {
    public static int findDepth(TreeNode root) {
        // TODO: Write your code here
        Queue<TreeNode> q = new LinkedList<>();
        int n, N, level=0;

        if(root != null) {
            q.add(root);
        }

        while(!q.isEmpty()) {
            N = q.size();
            level++;
            for(n=0; n<N; n++) {
                root = q.poll();
                if(root.left != null) {
                    q.add(root.left);
                }
                if(root.right != null) {
                    q.add(root.right);
                }
                if(root.left==null && root.right==null) {
                    return level;
                }
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(12);
        root.left = new TreeNode(7);
        root.right = new TreeNode(1);
        root.right.left = new TreeNode(10);
        root.right.right = new TreeNode(5);
        System.out.println("Tree Minimum Depth: " + MinimumBinaryTreeDepth.findDepth(root));
        root.left.left = new TreeNode(9);
        root.right.left.left = new TreeNode(11);
        System.out.println("Tree Minimum Depth: " + MinimumBinaryTreeDepth.findDepth(root));
    }
}

/*
https://leetcode.com/problems/minimum-depth-of-binary-tree/
class Solution {
    public int minDepth(TreeNode root) {
        int n, depth = 0;
        Queue<TreeNode> q = new LinkedList<TreeNode>();

        if(root!=null) {
            q.add(root);
        }

        while(q.size() > 0) {
            depth++;
            n = q.size();
            while(n > 0) {
                n--;
                root = q.poll();
                if(root.left==null && root.right==null) {
                    return depth;
                }
                if(root.left!=null) {
                    q.add(root.left);
                }
                if(root.right!=null) {
                    q.add(root.right);
                }
            }
        }

        return depth;
    }
}
 */