import java.util.*;
import java.util.stream.*;

class Program {
  public static int minRewards(int[] scores) {
    // Write your code here.
    int n, N=scores.length;
    int[] dp = new int[N];

    Arrays.fill(dp, 1);

    for(n=1; n<N; n++) {
      if(scores[n] > scores[n-1]) {
        dp[n] = 1+dp[n-1];
      }
    }

    for(n=N-2; n>=0; n--) {
      if(scores[n] > scores[n+1]) {
        dp[n] = Math.max(dp[n], 1+dp[n+1]);
      }
    }

    return IntStream.of(dp).sum();
  }
}
