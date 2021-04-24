import java.util.*;

class Program {
  public static int palindromePartitioningMinCuts(String str) {
    // Write your code here.
    int l, r, N=str.length();
    boolean[][] dp = new boolean[N][N];
    int[] cuts = new int[N];

    for(l=0; l<N; l++) {
      dp[l][l] = true;
    }

    for(l=N-1; l>=0; l--) {
      for(r=l+1; r<N; r++) {
        if(str.charAt(l)==str.charAt(r)) {
          if(l+1==r || dp[l+1][r-1]) {
            dp[l][r] = true;
          }
        }
      }
    }

    for(l=N-1; l>=0; l--) {
      cuts[l] = N;
      for(r=N-1; r>=l; r--) {
        if(dp[l][r]) {
          if(r==N-1) {
            cuts[l] = 0;
          } else {
            cuts[l] = Math.min(cuts[l], 1+cuts[r+1]);
          }
        }
      }
    }

    return cuts[0];
  }
}
