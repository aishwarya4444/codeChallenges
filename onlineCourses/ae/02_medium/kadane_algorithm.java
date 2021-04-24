import java.util.*;

class Program {
  public static int kadanesAlgorithm(int[] array) {
    // Write your code here.
    int n, N=array.length, sum=0, maxSum=Integer.MIN_VALUE;

    for(n=0; n<N; n++) {
      sum += array[n];
      if(sum < array[n]) {
        sum = array[n];
      }
      if(maxSum < sum) {
        maxSum = sum;
      }
    }

    return maxSum;
  }
}
