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

  public int binaryTreeDiameter(BinaryTree tree) {
    // Write your code here.
    dia = 0;
    getHeight(tree);
    return dia;
  }

  private static int dia;

  private static int getHeight(BinaryTree tree) {
    if(tree==null) {
      return 0;
    }

    int lh, rh;

    lh = getHeight(tree.left);
    rh = getHeight(tree.right);

    dia = Math.max(dia, lh+rh);

    return 1+Math.max(lh, rh);
  }
}
