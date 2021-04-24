import java.util.*;

class Program {
  public static List<Integer> inOrderTraverse(BST tree, List<Integer> array) {
    // Write your code here.
    inorder(tree, array);
    return array;
  }
  public static void inorder(BST node, List<Integer> array) {
    if(node==null) {
      return;
    }
    inorder(node.left, array);
    array.add(node.value);
    inorder(node.right, array);
  }

  public static List<Integer> preOrderTraverse(BST tree, List<Integer> array) {
    // Write your code here.
    preorder(tree, array);
    return array;
  }
  public static void preorder(BST node, List<Integer> array) {
    if(node==null) {
      return;
    }
    array.add(node.value);
    preorder(node.left, array);
    preorder(node.right, array);
  }

  public static List<Integer> postOrderTraverse(BST tree, List<Integer> array) {
    // Write your code here.
    postorder(tree, array);
    return array;
  }
  public static void postorder(BST node, List<Integer> array) {
    if(node==null) {
      return;
    }
    postorder(node.left, array);
    postorder(node.right, array);
    array.add(node.value);
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
  public static List<Integer> inOrderTraverse(BST tree, List<Integer> array) {
    // Write your code here.
		if(tree==null) {
			return array;
		}
		inOrderTraverse(tree.left, array);
		array.add(tree.value);
		inOrderTraverse(tree.right, array);
    return array;
  }

  public static List<Integer> preOrderTraverse(BST tree, List<Integer> array) {
    // Write your code here.
    if(tree==null) {
			return array;
		}
		array.add(tree.value);
		preOrderTraverse(tree.left, array);
		preOrderTraverse(tree.right, array);
    return array;
  }

  public static List<Integer> postOrderTraverse(BST tree, List<Integer> array) {
    // Write your code here.
		if(tree==null) {
			return array;
		}
		postOrderTraverse(tree.left, array);
		postOrderTraverse(tree.right, array);
    array.add(tree.value);
		return array;
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