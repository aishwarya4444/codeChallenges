import java.util.*;

class Program {
  // This is an input class. Do not edit.
  static class BinaryTree {
    public int value;
    public BinaryTree left = null;
    public BinaryTree right = null;
    public BinaryTree parent = null;

    public BinaryTree(int value) {
      this.value = value;
    }
  }

  public BinaryTree findSuccessor(BinaryTree tree, BinaryTree node) {
    // Write your code here.
    if(node.right != null) {
      node = node.right;
      while(node.left != null) {
        node = node.left;
      }
      return node;
    }

    while(node.parent != null && node.parent.right == node) {
      node = node.parent;
    }
    return node.parent;
  }
}
