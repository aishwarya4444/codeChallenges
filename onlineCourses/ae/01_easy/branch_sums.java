import java.util.*;

class Program {
  // This is the class of the input root. Do not edit it.
  public static class BinaryTree {
    int value;
    BinaryTree left;
    BinaryTree right;

    BinaryTree(int value) {
      this.value = value;
      this.left = null;
      this.right = null;
    }
  }

  public static List<Integer> branchSums(BinaryTree root) {
    // Write your code here.
    List<Integer> result = new ArrayList<Integer>();
    findSums(root, 0, result);
    return result;
  }

  public static void findSums(BinaryTree root, int sum, List<Integer> result) {
    // Write your code here.
    if(root==null) {
      return;
    }
    sum += root.value;
    if(root.left==null && root.right==null) {
      result.add(sum);
      return;
    }
    findSums(root.left, sum, result);
    findSums(root.right, sum, result);
  }
}
