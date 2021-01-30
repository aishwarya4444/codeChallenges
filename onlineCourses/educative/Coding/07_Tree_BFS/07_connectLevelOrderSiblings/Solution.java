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

    // level order traversal using 'next' pointer
    void printLevelOrder() {
        TreeNode nextLevelRoot = this;
        while (nextLevelRoot != null) {
            TreeNode current = nextLevelRoot;
            nextLevelRoot = null;
            while (current != null) {
                System.out.print(current.val + " ");
                if (nextLevelRoot == null) {
                    if (current.left != null)
                        nextLevelRoot = current.left;
                    else if (current.right != null)
                        nextLevelRoot = current.right;
                }
                current = current.next;
            }
            System.out.println();
        }
    }
};

class ConnectLevelOrderSiblings {
    public static void connect(TreeNode root) {
        // TODO: Write your code here
        Queue<TreeNode> q = new LinkedList<>();
        int n, N;
        TreeNode node;

        if(root != null) {
            q.add(root);
        }

        while(!q.isEmpty()) {
            N = q.size();
            node = null;

            for(n=0; n<N; n++) {
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
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(12);
        root.left = new TreeNode(7);
        root.right = new TreeNode(1);
        root.left.left = new TreeNode(9);
        root.right.left = new TreeNode(10);
        root.right.right = new TreeNode(5);
        ConnectLevelOrderSiblings.connect(root);
        System.out.println("Level order traversal using 'next' pointer: ");
        root.printLevelOrder();
    }
}


/*
https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
class Solution {
    public Node connect(Node root) {
        Queue<Node> q = new LinkedList<Node>();
        Node prev, curr;
        int n;

        if(root!=null) {
            q.add(root);
        }

        while(q.size() > 0) {
            n = q.size();
            prev = null;
            while(n > 0) {
                n--;
                curr = q.poll();
                if(prev!=null) {
                    prev.next = curr;
                }
                if(curr.left!=null) {
                    q.add(curr.left);
                }
                if(curr.right!=null) {
                    q.add(curr.right);
                }
                prev = curr;
            }
        }

        return root;
    }
}
 */