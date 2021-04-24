import java.util.*;

class Program {
  public static int[] largestRange(int[] array) {
    // Write your code here.
    int left, right, start=-1, end=-1, len=0;
    Map<Integer, Boolean> occur = new HashMap<>();

    for(Integer num: array) {
      occur.put(num, true);
    }

    for(Integer num: array) {
      if(occur.get(num) == false) {
        continue;
      }
      occur.put(num, false);
      left = num-1;
      right = num+1;

      while(occur.containsKey(left)) {
        occur.put(left, false);
        left--;
      }
      left++;

      while(occur.containsKey(right)) {
        occur.put(right, false);
        right++;
      }
      right--;

      if(len<right-left+1) {
        len = right-left+1;
        start = left;
        end = right;
      }
    }

    return new int[] {start, end};
  }
}
