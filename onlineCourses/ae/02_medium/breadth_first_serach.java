import java.util.*;

class Program {
  // Do not edit the class below except
  // for the breadthFirstSearch method.
  // Feel free to add new properties
  // and methods to the class.
  static class Node {
    String name;
    List<Node> children = new ArrayList<Node>();

    public Node(String name) {
      this.name = name;
    }

    public List<String> breadthFirstSearch(List<String> array) {
      // Write your code here.
      Queue<Node> q = new LinkedList<>();
      Node root = this;

      if(root != null) {
        q.add(root);
      }

      while(q.size() != 0) {
        root = q.poll();
        array.add(root.name);
        q.addAll(root.children);
        // for(Node node: root.children) {
        // 	q.add(node);
        // }
      }

      return array;
    }

    public Node addChild(String name) {
      Node child = new Node(name);
      children.add(child);
      return this;
    }
  }
}
