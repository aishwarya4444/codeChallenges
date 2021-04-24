import java.util.*;

class Program {
  // This is an input class. Do not edit.
  static class BinaryTree {
    public int value;
    public BinaryTree left = null;
    public BinaryTree right = null;

    public BinaryTree(int value) {
      this.value = value;
    }
  }

  public ArrayList<Integer> findNodesDistanceK(BinaryTree tree, int target, int k) {
    // Write your code here.
    // O(n) time and O(n) space
    ArrayList<Integer> res = new ArrayList<Integer>();

    findDistFromNodeToTarget(tree, target, k, res);

    return res;
  }

  public int findDistFromNodeToTarget(BinaryTree node, int target, int k, ArrayList<Integer> res) {
    if(node==null) {
      return -1;
    }

    if(node.value == target) {
      addSubtreeNodesAtDistanceK(node, 0, k, res);
      return 1;
    }

    int leftDist = findDistFromNodeToTarget(node.left, target, k, res);
    int rightDist = findDistFromNodeToTarget(node.right, target, k, res);

    if(leftDist==k || rightDist==k) {
      res.add(node.value);
    }

    if(leftDist != -1) {
      addSubtreeNodesAtDistanceK(node.right, leftDist+1, k, res);
      return leftDist+1;
    }

    if(rightDist != -1) {
      addSubtreeNodesAtDistanceK(node.left, rightDist+1, k, res);
      return rightDist+1;
    }

    return -1;
  }

  public void addSubtreeNodesAtDistanceK(BinaryTree node, int dist, int k, ArrayList<Integer> res) {
    if(node == null) {
      return;
    }

    if(dist==k) {
      res.add(node.value);
    } else {
      addSubtreeNodesAtDistanceK(node.left, 1+dist, k, res);
      addSubtreeNodesAtDistanceK(node.right, 1+dist, k, res);
    }
  }
}
