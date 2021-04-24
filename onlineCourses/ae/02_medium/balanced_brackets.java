import java.util.*;

class Program {
  public static boolean balancedBrackets(String str) {
    // Write your code here.
    Stack<Character> st = new Stack<>();
    String brackets = "(){}[]";
    int top;

    for(char ch: str.toCharArray()) {
      if(brackets.indexOf(ch) == -1) {
        continue;
      }

      if(ch=='{' || ch=='(' || ch=='[') {
        st.push(ch);
      } else {
        if(st.size()==0) {
          return false;
        }
        top = st.peek();
        if(
            (top=='(' && ch==')') ||
                (top=='[' && ch==']') ||
                (top=='{' && ch=='}') ) {
          st.pop();
        } else {
          return false;
        }
      }
    }
    return st.size()==0;
  }
}
