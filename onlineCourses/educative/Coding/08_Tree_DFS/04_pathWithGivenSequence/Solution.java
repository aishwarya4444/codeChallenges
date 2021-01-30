import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
};

class PathWithGivenSequence {
    private static boolean help(TreeNode root, int[] sequence, int pos) {
        if(root==null) {
            return false;
        }
        if(pos>=sequence.length || root.val!=sequence[pos]) {
            return false;
        }
        if(root.left==null && root.right==null && pos==sequence.length-1) {
            return true;
        }
        return help(root.left, sequence, pos+1) || help(root.right, sequence, pos+1);
    }
    public static boolean findPath(TreeNode root, int[] sequence) {
        // TODO: Write your code here
        if(root==null && sequence.length==0) {
            return false;
        }
        return help(root, sequence, 0);
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(0);
        root.right = new TreeNode(1);
        root.left.left = new TreeNode(1);
        root.right.left = new TreeNode(6);
        root.right.right = new TreeNode(5);

        System.out.println("Tree has path sequence: " + PathWithGivenSequence.findPath(root, new int[] { 1, 0, 7 }));
        System.out.println("Tree has path sequence: " + PathWithGivenSequence.findPath(root, new int[] { 1, 1, 6 }));
    }
}
