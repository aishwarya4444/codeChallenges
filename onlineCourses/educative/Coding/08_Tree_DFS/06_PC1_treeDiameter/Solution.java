// here diameter is number of nodes
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
};

class TreeDiameter {
    private static int diameter = 0;

    private static int findHeight(TreeNode root) {
        if(root==null) {
            return 0;
        }

        int lh = 0, rh = 0;
        lh = findHeight(root.left);
        rh = findHeight(root.right);

        diameter = Math.max(diameter, 1+lh+rh);

        return 1+Math.max(lh, rh);
    }

    public static int findDiameter(TreeNode root) {
        // TODO: Write your code here
        findHeight(root);
        return diameter;
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.right.left = new TreeNode(5);
        root.right.right = new TreeNode(6);
        System.out.println("Tree Diameter: " + TreeDiameter.findDiameter(root));
        root.left.left = null;
        root.right.left.left = new TreeNode(7);
        root.right.left.right = new TreeNode(8);
        root.right.right.left = new TreeNode(9);
        root.right.left.right.left = new TreeNode(10);
        root.right.right.left.left = new TreeNode(11);
        System.out.println("Tree Diameter: " + TreeDiameter.findDiameter(root));
    }
}


/*
https://leetcode.com/problems/diameter-of-binary-tree/
// here diameter is number of connecting paths which is 1 less than total number of nodes

// Solution 1
class Solution {
    private int diameter = 0;

    private int findHeight(TreeNode root) {
        if(root==null) {
            return 0;
        }

        int lh = findHeight(root.left);
        int rh = findHeight(root.right);

        diameter = Math.max(diameter, 1+lh+rh);

        return 1+Math.max(lh, rh);
    }
    public int diameterOfBinaryTree(TreeNode root) {
        findHeight(root);
        return diameter>0 ? diameter-1 : 0;
    }
}

// Solution 2
class Solution {
    private int diameter = 0;

    private int findHeight(TreeNode root) {
        if(root==null) {
            return 0;
        }

        int lh = findHeight(root.left);
        int rh = findHeight(root.right);

        diameter = Math.max(diameter, lh+rh);

        return 1+Math.max(lh, rh);
    }
    public int diameterOfBinaryTree(TreeNode root) {
        findHeight(root);
        return diameter;
    }
}
 */