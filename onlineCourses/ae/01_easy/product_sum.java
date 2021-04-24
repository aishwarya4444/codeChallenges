import java.util.*;

class Program {
  // Tip: You can use `element instanceof ArrayList` to check whether an item
  // is an array or an integer.
  public static int productSum(List<Object> array) {
    // Write your code here.
    return sumHelper(array, 1);
  }
  private static int sumHelper(List<Object> array, int factor) {
    int sum = 0;

    for(Object ob: array) {
      if(ob instanceof ArrayList) {
        @SuppressWarnings("unchecked")
        List<Object> subArray = (ArrayList<Object>)ob;
        sum += sumHelper(subArray, factor+1);
      } else {
        sum += (int)ob;
      }
    }

    return factor*sum;
  }
}
