import java.util.function.Function;

class Program {
  public static void iterativeInOrderTraversal(
      BinaryTree tree, Function<BinaryTree, Void> callback) {
    // Write your code here.
    // O(n) time and O(1) space
    BinaryTree prev = null;
    BinaryTree curr = tree;

    while(curr != null) {
      BinaryTree next;
      if(prev==null || prev==curr.parent) {
        if(curr.left != null) {
          next = curr.left;
        } else {
          callback.apply(curr);
          next = curr.right!=null ? curr.right : curr.parent;
        }
      } else if(prev == curr.left) {
        callback.apply(curr);
        next = curr.right!=null ? curr.right : curr.parent;
      } else {
        next = curr.parent;
      }
      prev = curr;
      curr = next;
    }
  }

  static class BinaryTree {
    public int value;
    public BinaryTree left;
    public BinaryTree right;
    public BinaryTree parent;

    public BinaryTree(int value) {
      this.value = value;
    }

    public BinaryTree(int value, BinaryTree parent) {
      this.value = value;
      this.parent = parent;
    }
  }
}
