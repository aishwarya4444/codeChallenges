import java.util.*;

class Program {
  // This is an input class. Do not edit.
  static class BST {
    public int value;
    public BST left = null;
    public BST right = null;

    public BST(int value) {
      this.value = value;
    }
  }

  private static class TreeInfo {
    public int nodes;
    public int prev;
    TreeInfo(int nodes, int prev) {
      this.nodes = nodes;
      this.prev = prev;
    }
  }

  public int findKthLargestValueInBst(BST tree, int k) {
    // Write your code here.
    TreeInfo info = new TreeInfo(0, 0);
    reverseInorder(tree, k, info);
    return info.prev;
  }

  private static void reverseInorder(BST node, int k, TreeInfo info) {
    if(node==null || info.nodes>=k) {
      return;
    }
    reverseInorder(node.right, k, info);
    if(info.nodes<k) {
      info.nodes++;
      info.prev = node.value;
      reverseInorder(node.left, k, info);
    }
  }
}
