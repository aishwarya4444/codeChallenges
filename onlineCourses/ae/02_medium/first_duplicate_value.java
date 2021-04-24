import java.util.*;

class Program {

  public int firstDuplicateValue(int[] array) {
    // Write your code here.
    Set<Integer> visited = new HashSet<Integer>();

    for(int num: array) {
      if(visited.contains(num)) {
        return num;
      }
      visited.add(num);
    }
    return -1;
  }
}
