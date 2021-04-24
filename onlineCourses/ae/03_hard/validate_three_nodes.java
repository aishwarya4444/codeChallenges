import java.util.*;

class Program {
  // This is an input class. Do not edit.
  // O(h) time and O(1) space
  static class BST {
    public int value;
    public BST left = null;
    public BST right = null;

    public BST(int value) {
      this.value = value;
    }
  }

  public boolean validateThreeNodes(BST nodeOne, BST nodeTwo, BST nodeThree) {
    // Write your code here.
    if(isParent(nodeOne, nodeTwo)) {
      return isParent(nodeTwo, nodeThree);
    }

    if(isParent(nodeThree, nodeTwo)) {
      return isParent(nodeTwo, nodeOne);
    }

    return false;
  }

  private static boolean isParent(BST parent, BST child) {
    while(parent!=null && parent!=child) {
      if(child.value<parent.value) {
        parent = parent.left;
      } else {
        parent = parent.right;
      }
    }

    return parent==child;
  }
}
