import java.util.*;

class Program {
  public static BST minHeightBst(List<Integer> array) {
    // Write your code here.
    return makeBalancedBST(array, 0, array.size()-1);
  }
  private static BST makeBalancedBST(List<Integer> array, int lb, int ub) {
    if(lb>ub) {
      return null;
    }
    int mid = lb+(ub-lb)/2;
    BST node = new BST(array.get(mid));
    node.left = makeBalancedBST(array, lb, mid-1);
    node.right = makeBalancedBST(array, mid+1, ub);
    return node;
  }

  static class BST {
    public int value;
    public BST left;
    public BST right;

    public BST(int value) {
      this.value = value;
      left = null;
      right = null;
    }

    public void insert(int value) {
      if (value < this.value) {
        if (left == null) {
          left = new BST(value);
        } else {
          left.insert(value);
        }
      } else {
        if (right == null) {
          right = new BST(value);
        } else {
          right.insert(value);
        }
      }
    }
  }
}
