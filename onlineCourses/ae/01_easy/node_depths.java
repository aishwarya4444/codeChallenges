import java.util.*;

class Program {

  private static int result;
  public static int nodeDepths(BinaryTree root) {
    // Write your code here.
    result = 0;
    depthHelp(root, 0);
    return result;
  }

  public static void depthHelp(BinaryTree root, int depth) {
    if(root==null) {
      return;
    }

    result += depth;
    depthHelp(root.left, 1+depth);
    depthHelp(root.right, 1+depth);
  }

  static class BinaryTree {
    int value;
    BinaryTree left;
    BinaryTree right;

    public BinaryTree(int value) {
      this.value = value;
      left = null;
      right = null;
    }
  }
}
