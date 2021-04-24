import java.util.*;

class Program {
  public static int minNumberOfJumps(int[] array) {
    // Write your code here.
    // O(N^2) time and O(1) space
    int i, j, N=array.length;
    int[] dp = new int[N];

    Arrays.fill(dp, Integer.MAX_VALUE);
    dp[0] = 0;

    for(i=1; i<N; i++) {
      for(j=0; j<i; j++) {
        if(j+array[j] >= i) {
          dp[i] = Math.min(1+dp[j], dp[i]);
        }
      }
    }

    return dp[N-1]==Integer.MAX_VALUE ? -1 : dp[N-1];
  }
}
