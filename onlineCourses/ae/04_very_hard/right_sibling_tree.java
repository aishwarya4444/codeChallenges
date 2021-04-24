import java.util.*;

class Program {
  public static BinaryTree rightSiblingTree(BinaryTree root) {
    // Write your code here.
    mutate(root, null, false);
    return root;
  }

  private static void mutate(BinaryTree node, BinaryTree parent, boolean isLeftChild) {
    if(node==null) {
      return;
    }

    BinaryTree left=node.left, right=node.right;

    mutate(left, node, true);
    if(parent==null) {
      node.right = null;
    } else if(isLeftChild) {
      node.right = parent.right;
    } else {
      node.right = parent.right == null ? null : parent.right.left;
    }
    mutate(right, node, false);
  }

  // This is the class of the input root. Do not edit it.
  static class BinaryTree {
    int value;
    BinaryTree left = null;
    BinaryTree right = null;

    public BinaryTree(int value) {
      this.value = value;
    }
  }
}
