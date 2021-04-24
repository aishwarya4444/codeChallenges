import java.util.*;

class Program {
  public static boolean isValidSubsequence(List<Integer> array, List<Integer> sequence) {
    // Write your code here.

    int i=0;
    for(Integer num: array) {
      if(i == sequence.size()) {
        break;
      }
      if(sequence.get(i).equals(num)) {
        i++;
      }
    }
    return i==sequence.size();
  }
}
