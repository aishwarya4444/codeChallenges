import java.util.*;

class Program {
  static class BST {
    public int value;
    public BST left;
    public BST right;

    public BST(int value) {
      this.value = value;
    }

    public BST insert(int value) {
      // Write your code here.
      // Do not edit the return statement of this method.
      // Average : O(lg n) time and O(1) space
      // Worst : O(n) time and O(1) space
      BST curr = this;
      while(true) {
        if(value < curr.value) {
          if(curr.left == null) {
            BST tmp = new BST(value);
            curr.left = tmp;
            break;
          } else {
            curr = curr.left;
          }
        } else {
          if(curr.right == null) {
            BST tmp = new BST(value);
            curr.right = tmp;
            break;
          } else {
            curr = curr.right;
          }
        }
      }
      return this;
    }

    public boolean contains(int value) {
      // Write your code here.
      // Average : O(lg n) time and O(1) space
      // Worst : O(n) time and O(1) space
      BST curr = this;
      while(curr != null) {
        if(value < curr.value) {
          curr = curr.left;
        } else if(value > curr.value) {
          curr = curr.right;
        } else {
          return true;
        }
      }
      return false;
    }

    public BST remove(int value) {
      // Write your code here.
      // Do not edit the return statement of this method.
      // Average : O(lg n) time and O(1) space
      // Worst : O(n) time and O(1) space
      remove(value, null);
      return this;
    }

    public void remove(int value, BST parent) {
      BST curr = this;
      while(curr != null) {
        if(value < curr.value) {
          parent = curr;
          curr = curr.left;
        } else if(value > curr.value) {
          parent = curr;
          curr = curr.right;
        } else {
          if(curr.left!=null && curr.right!=null) {
            curr.value = curr.right.getMinValue();
            curr.right.remove(curr.value, curr);
          } else if(parent == null) {
            if(curr.left != null) {
              curr.value = curr.left.value;
              curr.right = curr.left.right;
              curr.left = curr.left.left;
            } else if (curr.right != null) {
              curr.value = curr.right.value;
              curr.left = curr.right.left;
              curr.right = curr.right.right;
            } else {
              // single node tree
              // do not do anything
            }
          } else if(parent.left == curr) {
            parent.left = curr.left!=null ? curr.left : curr.right;
          } else if(parent.right == curr) {
            parent.right = curr.left!=null ? curr.left : curr.right;
          }
          break;
        }
      }
    }

    public int getMinValue() {
      if(left == null) {
        return value;
      } else {
        return left.getMinValue();
      }
    }
  }
}
