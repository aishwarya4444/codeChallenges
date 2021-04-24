import java.util.*;

class Program {
  // This is an input class. Do not edit.
  static class BinaryTree {
    public int value;
    public BinaryTree left = null;
    public BinaryTree right = null;

    public BinaryTree(int value) {
      this.value = value;
    }
  }

  static class TreeInfo {
    public boolean balanced;
    public int height;

    TreeInfo(boolean balanced, int height) {
      this.balanced = balanced;
      this.height = height;
    }
  }

  public boolean heightBalancedBinaryTree(BinaryTree tree) {
    // Write your code here.
    TreeInfo treeInfo = findBalanced(tree);
    return treeInfo.balanced;
  }

  private TreeInfo findBalanced(BinaryTree tree) {
    if(tree == null) {
      return new TreeInfo(true, -1);
    }

    TreeInfo leftTree = findBalanced(tree.left);
    TreeInfo rightTree = findBalanced(tree.right);

    int lh = leftTree.height, rh = rightTree.height;
    boolean lb = leftTree.balanced, rb = rightTree.balanced;

    return new TreeInfo(lb && rb && Math.abs(lh-rh)<=1, 1+Math.max(lh, rh));
  }
}
