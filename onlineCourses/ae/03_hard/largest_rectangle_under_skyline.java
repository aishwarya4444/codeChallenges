import java.util.*;

class Program {

  public int largestRectangleUnderSkyline(ArrayList<Integer> buildings) {
    // Write your code here.
    // https://github.com/aishwarya4444/leetcode.com/blob/master/leetcodeSolutions.cpp#L1907
    // https://github.com/aishwarya4444/leetcode.com/blob/master/leetcodeSolutions.cpp#L1633
    Stack<Integer> st = new Stack<>();
    int count, area=0;

    for(Integer height: buildings) {
      if(st.size()==0 || height>=st.peek()) {
        st.push(height);
      } else {
        count = 0;
        while(st.size()>0 && height<st.peek()) {
          count++;
          area = Math.max(area, count*st.pop());
        }
        while(count>=0) {
          count--;
          st.push(height);
        }
      }
    }

    count = 0;
    while(st.size()>0) {
      count++;
      area = Math.max(area, count*st.pop());
    }
    return area;
  }
}
