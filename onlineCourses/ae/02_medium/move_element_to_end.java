import java.util.*;

class Program {
  public static List<Integer> moveElementToEnd(List<Integer> array, int toMove) {
    // Write your code here.
    int start=0, end=array.size()-1;

    while(start < end) {
      if(array.get(start) != toMove) {
        start++;
      } else {
        array.set(start, array.get(end));
        array.set(end, toMove);
        end--;
      }
    }
    return array;
  }
}
