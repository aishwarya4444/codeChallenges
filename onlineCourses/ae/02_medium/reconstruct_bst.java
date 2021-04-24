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

  public BST reconstructBst(ArrayList<Integer> preOrderTraversalValues) {
    // Write your code here.
    // O(n) time and O(n) space where n is size of preOrderTraversalValues
    TreeInfo treeInfo = new TreeInfo(0);

    return reconstructBstFromRange(Integer.MIN_VALUE, Integer.MAX_VALUE, preOrderTraversalValues, treeInfo);
  }

  static class TreeInfo {
    public int rootIdx;

    public TreeInfo(int rootIdx) {
      this.rootIdx = rootIdx;
    }
  }

  static BST reconstructBstFromRange(int min, int max, List<Integer> preorder, TreeInfo subtreeInfo) {
    if(subtreeInfo.rootIdx == preorder.size()) {
      return null;
    }

    int val = preorder.get(subtreeInfo.rootIdx);
    if(val<min || val>=max) {
      return null;
    }

    subtreeInfo.rootIdx += 1;
    BST leftSubtree = reconstructBstFromRange(min, val, preorder, subtreeInfo);
    BST rightSubtree = reconstructBstFromRange(val, max, preorder, subtreeInfo);

    BST bst = new BST(val);
    bst.left = leftSubtree;
    bst.right = rightSubtree;

    return bst;
  }
}
