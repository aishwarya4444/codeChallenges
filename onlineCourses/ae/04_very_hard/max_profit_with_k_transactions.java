import java.util.*;

class Program {
  public static int maxProfitWithKTransactions(int[] prices, int k) {
    // Write your code here.
    int i, tran, profit=0, N=prices.length;

    if(k >= N/2) {
      for(i=1; i<N; i++) {
        if(prices[i]>prices[i-1]) {
          profit += prices[i]-prices[i-1];
        }
      }
      return profit;
    }

    int[][] dp = new int[k+1][N];

    for(tran=1; tran<=k; tran++) {
      profit = Integer.MIN_VALUE;
      for(i=1; i<N; i++) {
        profit = Math.max(profit, dp[tran-1][i-1]-prices[i-1]);
        dp[tran][i] = Math.max(dp[tran][i-1], profit+prices[i]);
      }
    }

    return dp[k][N-1];
  }
}
