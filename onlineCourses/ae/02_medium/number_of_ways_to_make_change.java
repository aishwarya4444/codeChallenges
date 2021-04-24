import java.util.*;

class Program {
  public static int numberOfWaysToMakeChange(int n, int[] denoms) {
    // Write your code here.
    int[][] dp = new int[denoms.length][n+1];
    int r, c;

    for(r=0; r<denoms.length; r++) {
      dp[r][0] = 1;
    }

    for(r=0; r<denoms.length; r++) {
      for(c=1; c<=n; c++) {
        if(denoms[r] <= c) {
          dp[r][c] = dp[r][c-denoms[r]];
        }
        if(r > 0) {
          dp[r][c] += dp[r-1][c];
        }
      }
    }

    return dp[denoms.length-1][n];
  }
}

/*
import java.util.*;

class Program {
  public static int numberOfWaysToMakeChange(int n, int[] denoms) {
    // Write your code here.
		int[] ways = new int[n+1];

		ways[0] = 1;
		for(int denom: denoms) {
			for(int amount=1; amount<=n; amount++) {
				if(amount >= denom) {
					ways[amount] += ways[amount-denom];
				}
			}
		}

    return ways[n];
  }
}
 */