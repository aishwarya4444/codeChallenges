import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
};

class LevelOrderSuccessor {
    public static TreeNode findSuccessor(TreeNode root, int key) {
        // TODO: Write your code here
        Queue<TreeNode> q = new LinkedList<>();
        TreeNode pre = null;

        if(root != null) {
            q.add(root);
        }

        while(!q.isEmpty()) {
            root = q.poll();
            if(pre != null) {
                return root;
            }
            if(root.val == key) {
                pre = root;
            }
            if(root.left != null) {
                q.add(root.left);
            }
            if(root.right != null) {
                q.add(root.right);
            }
        }
        return null;
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(12);
        root.left = new TreeNode(7);
        root.right = new TreeNode(1);
        root.left.left = new TreeNode(9);
        root.right.left = new TreeNode(10);
        root.right.right = new TreeNode(5);
        TreeNode result = LevelOrderSuccessor.findSuccessor(root, 12);
        if (result != null)
            System.out.println(result.val + " ");
        result = LevelOrderSuccessor.findSuccessor(root, 9);
        if (result != null)
            System.out.println(result.val + " ");
    }
}
