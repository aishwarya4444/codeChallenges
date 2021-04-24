import java.util.*;

class Program {
  public static List<Integer[]> threeNumberSum(int[] array, int targetSum) {
    // Write your code here.
    List<Integer[]> result = new ArrayList<Integer[]>();
    int i, j, k, N=array.length, sum;

    Arrays.sort(array);
    for(i=0; i<N-2; i++) {
      j = i+1;
      k = N-1;
      while(j<k) {
        sum = array[i]+array[j]+array[k];
        if(sum == targetSum) {
          Integer[] triplet = {array[i], array[j], array[k]};
          result.add(triplet);
          j++;
          k--;
        } else if(sum < targetSum) {
          j++;
        } else {
          k--;
        }
      }
    }
    return result;
  }
}
