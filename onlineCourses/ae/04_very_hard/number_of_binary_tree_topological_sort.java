import java.util.*;

class Program {
  public static int numberOfBinaryTreeTopologies(int n) {
    // Write your code here.
    if(n < 2) {
      return 1;
    }
    int[] dp = new int[n+1];
    int i, j;

    dp[0] = 1;
    dp[1] = 1;
    for(i=2; i<=n; i++) {
      for(j=0; j<i; j++) {
        dp[i] += dp[j]*dp[i-1-j];
      }
    }

    return dp[n];
  }
}
