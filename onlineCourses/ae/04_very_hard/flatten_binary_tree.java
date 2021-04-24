import java.util.*;

class Program {
  public static BinaryTree flattenBinaryTree(BinaryTree root) {
    // Write your code here.
    // O(n) time and O(n) space
    List<BinaryTree> res = new ArrayList<>();

    inorder(root, res);

    for(int i=0; i<res.size()-1; i++) {
      BinaryTree left = res.get(i);
      BinaryTree right = res.get(i+1);
      left.right = right;
      right.left = left;
    }

    return root==null ? root : res.get(0);
  }

  public static void inorder(BinaryTree node, List<BinaryTree> res) {
    if(node == null) {
      return;
    }

    inorder(node.left, res);
    res.add(node);
    inorder(node.right, res);
  }

  // This is the class of the input root. Do not edit it.
  static class BinaryTree {
    int value;
    BinaryTree left = null;
    BinaryTree right = null;

    public BinaryTree(int value) {
      this.value = value;
    }
  }
}
