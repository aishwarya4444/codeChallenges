import java.util.*;

class Program {
  public static int allKindsOfNodeDepths(BinaryTree root) {
    // Write your code here.
    return getTreeInfo(root).sumAllDepths;
  }

  private static TreeInfo getTreeInfo(BinaryTree root) {
    if(root==null) {
      return new TreeInfo(0, 0, 0);
    }

    TreeInfo left = getTreeInfo(root.left);
    TreeInfo right = getTreeInfo(root.right);

    int l_sumDepths = left.sumDepths + left.numNodesInTree;
    int r_sumDepths = right.sumDepths + right.numNodesInTree;

    int numNodesInTree = 1 + left.numNodesInTree + right.numNodesInTree;
    int sumDepths = l_sumDepths + r_sumDepths;
    int sumAllDepths = sumDepths + left.sumAllDepths + right.sumAllDepths;

    return new TreeInfo(numNodesInTree, sumDepths, sumAllDepths);
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

  static class TreeInfo {
    int numNodesInTree;
    int sumDepths;
    int sumAllDepths;

    TreeInfo(int numNodesInTree, int sumDepths, int sumAllDepths) {
      this.numNodesInTree = numNodesInTree;
      this.sumDepths = sumDepths;
      this.sumAllDepths = sumAllDepths;
    }
  }
}
