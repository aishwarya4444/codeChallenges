import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
};

class RightViewTree {
    public static List<TreeNode> traverse(TreeNode root) {
        List<TreeNode> result = new ArrayList<>();
        // TODO: Write your code here
        Queue<TreeNode> q = new LinkedList<>();
        int n, N;

        if(root != null) {
            q.add(root);
        }

        while(!q.isEmpty()) {
            N = q.size();

            for(n=0; n<N; n++) {
                root = q.poll();
                if(root.left != null) {
                    q.add(root.left);
                }
                if(root.right != null) {
                    q.add(root.right);
                }
            }
            result.add(root);
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
        root.left.left.left = new TreeNode(3);
        List<TreeNode> result = RightViewTree.traverse(root);
        for (TreeNode node : result) {
            System.out.print(node.val + " ");
        }
    }
}



/*
https://leetcode.com/problems/binary-tree-right-side-view/
class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> res = new ArrayList<Integer>();
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        int n;

        if(root!=null) {
            q.add(root);
        }

        while(q.size() > 0) {
            n = q.size();
            while(n > 0) {
                n--;
                root = q.poll();
                if(root.left!=null) {
                    q.add(root.left);
                }
                if(root.right!=null) {
                    q.add(root.right);
                }
            }
            res.add(root.val);
        }

        return res;
    }
}
 */