import java.util.*;

class Program {
  public static int minNumberOfCoinsForChange(int n, int[] denoms) {
    // Write your code here.
    int[][] dp = new int[denoms.length][n+1];
    int r, c;
    int ways1, ways2;

    for(r=0; r<denoms.length; r++) {
      for(c=1; c<=n; c++) {
        ways1 = Integer.MAX_VALUE;
        ways2 = Integer.MAX_VALUE;
        if(denoms[r] <= c) {
          ways1 = dp[r][c-denoms[r]];
          if(ways1 != Integer.MAX_VALUE) {
            ways1++;
          }
        }
        if(r > 0) {
          ways2 = dp[r-1][c];
        }
        dp[r][c] = Math.min(ways1, ways2);
      }
    }

    return dp[denoms.length-1][n] == Integer.MAX_VALUE ? -1 : dp[denoms.length-1][n];
  }
}

/*
import java.util.*;

class Program {
  public static int minNumberOfCoinsForChange(int n, int[] denoms) {
    // Write your code here.
		int[] ways = new int[n+1];

		Arrays.fill(ways, Integer.MAX_VALUE);
		ways[0] = 0;
		for(int denom: denoms) {
			for(int amount=1; amount<=n; amount++) {
				if(amount >= denom) {
					int count = ways[amount-denom];
					if(count != Integer.MAX_VALUE) {
						ways[amount] = Math.min(ways[amount], 1+count);
					}
				}
			}
		}
    return ways[n]==Integer.MAX_VALUE ? -1 : ways[n];
  }
}
 */