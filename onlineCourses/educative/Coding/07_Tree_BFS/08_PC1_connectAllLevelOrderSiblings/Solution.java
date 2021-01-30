import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode next;

    TreeNode(int x) {
        val = x;
        left = right = next = null;
    }
};

class ConnectAllSiblings {
    public static void connect(TreeNode root) {
        // TODO: Write your code here
        Queue<TreeNode> q = new LinkedList<>();
        TreeNode node = null;

        if(root != null) {
            q.add(root);
        }

        while(!q.isEmpty()) {
            root = q.poll();
            if(node != null) {
                node.next = root;
            }
            node = root;
            if(root.left != null) {
                q.add(root.left);
            }
            if(root.right != null) {
                q.add(root.right);
            }
        }
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(12);
        root.left = new TreeNode(7);
        root.right = new TreeNode(1);
        root.left.left = new TreeNode(9);
        root.right.left = new TreeNode(10);
        root.right.right = new TreeNode(5);
        ConnectAllSiblings.connect(root);

        // level order traversal using 'next' pointer
        TreeNode current = root;
        System.out.println("Traversal using 'next' pointer: ");
        while (current != null) {
            System.out.print(current.val + " ");
            current = current.next;
        }
    }
}