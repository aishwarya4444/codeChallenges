import java.util.*;

class Program {
  public static int maxPathSum(BinaryTree tree) {
    // Write your code here.
    sum = Integer.MIN_VALUE;
    findSum(tree);
    return sum;
  }

  private static int sum;
  private static int findSum(BinaryTree node) {
    if(node==null) {
      return 0;
    }

    int lSum = Math.max(0, findSum(node.left));
    int rSum = Math.max(0, findSum(node.right));

    sum = Math.max(sum, node.value + lSum + rSum);

    return node.value + Math.max(lSum, rSum);
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
