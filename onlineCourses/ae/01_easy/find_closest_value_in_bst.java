import java.util.*;

class Program {
  public static int findClosestValueInBst(BST tree, int target) {
    // Write your code here.
    Queue<BST> q = new LinkedList<>();
    int result = -1;

    if(tree!=null) {
      q.add(tree);
      result = tree.value;
    }

    while(q.size() > 0) {
      tree = q.poll();
      if(Math.abs(target-result) > Math.abs(target-tree.value)) {
        result = tree.value;
      }
      if(tree.left!=null) {
        q.add(tree.left);
      }
      if(tree.right!=null) {
        q.add(tree.right);
      }
    }
    return result;
  }

  static class BST {
    public int value;
    public BST left;
    public BST right;

    public BST(int value) {
      this.value = value;
    }
  }
}


/*
import java.util.*;

class Program {
  public static int findClosestValueInBst(BST tree, int target) {
    // Write your code here.
		int result = tree.value;

		while(tree!=null) {
			if(Math.abs(target-result) > Math.abs(target-tree.value)) {
				result = tree.value;
			}
			if(target<tree.value) {
				tree = tree.left;
			} else if(target>tree.value) {
				tree = tree.right;
			} else {
				break;
			}
		}
    return result;
  }

  static class BST {
    public int value;
    public BST left;
    public BST right;

    public BST(int value) {
      this.value = value;
    }
  }
}
 */