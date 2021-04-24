import java.util.*;

class Program {
  public static boolean validateBst(BST tree) {
    // Write your code here.
    return dfs(tree, Integer.MIN_VALUE, Integer.MAX_VALUE);
  }

  public static boolean dfs(BST tree, int minValue, int maxValue) {
    if(tree==null) {
      return true;
    }

    if(minValue>tree.value || tree.value>=maxValue) {
      return false;
    }

    return dfs(tree.left, minValue, tree.value) && dfs(tree.right, tree.value, maxValue);
  }

  static class BST {
    public int value;
    public BST left;
    public BST right;

    public BST(int value) {
      this.value = value;
    }
  }
}
