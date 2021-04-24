import java.util.*;

class Program {
  public static int maxSubsetSumNoAdjacent(int[] array) {
    // Write your code here.
    int n, N=array.length;
    int[] dp = new int[N+1];

    if(N == 0) {
      return 0;
    }

    dp[1] = array[0];
    for(n=2; n<=N; n++) {
      dp[n] = Math.max(array[n-1]+dp[n-2], dp[n-1]);
    }

    return dp[N];
  }
}
