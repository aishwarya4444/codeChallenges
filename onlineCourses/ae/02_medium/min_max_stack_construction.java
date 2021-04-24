import java.util.*;

class Program {
  // Feel free to add new properties and methods to the class.
  static class MinMaxStack {
    class Node {
      int num;
      int min;
      int max;
      Node(int num, int min, int max) {
        this.num = num;
        this.min = min;
        this.max = max;
      }
    }

    Stack<Node> st = new Stack<>();

    public int peek() {
      // Write your code here.
      return st.peek().num;
    }

    public int pop() {
      // Write your code here.
      return st.pop().num;
    }

    public void push(Integer number) {
      // Write your code here.
      if(st.size()==0) {
        st.push(new Node(number, number, number));
        return;
      }

      Node node = st.peek();
      int min=Math.min(node.min, number), max=Math.max(node.max, number);

      st.push(new Node(number, min, max));
    }

    public int getMin() {
      // Write your code here.
      return st.peek().min;
    }

    public int getMax() {
      // Write your code here.
      return st.peek().max;
    }
  }
}
