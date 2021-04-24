import java.util.*;

class Program {
  public static void invertBinaryTree(BinaryTree tree) {
    // Write your code here.
    if(tree==null) {
      return;
    }

    BinaryTree left = tree.left, right = tree.right;

    invertBinaryTree(tree.left);
    invertBinaryTree(tree.right);

    tree.left = right;
    tree.right = left;
  }

  static class BinaryTree {
    public int value;
    public BinaryTree left;
    public BinaryTree right;

    public BinaryTree(int value) {
      this.value = value;
    }
  }
}
