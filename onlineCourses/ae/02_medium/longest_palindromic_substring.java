import java.util.*;

class Program {
  public static String longestPalindromicSubstring(String str) {
    // Write your code here.
    int len=1, l, r, N=str.length();
    boolean[][] dp = new boolean[N][N];
    String res = N>0 ? str.substring(0, 1) : "";

    for(l=0; l<N; l++) {
      dp[l][l] = true;
    }

    for(l=N-1; l>=0; l--) {
      for(r=l+1; r<N; r++) {
        dp[l][r] = false;
        if(str.charAt(l)==str.charAt(r)) {
          if(l+1==r || dp[l+1][r-1]==true) {
            dp[l][r] = true;
            if(len<r-l+1) {
              len = r-l+1;
              res = str.substring(l, r+1);
            }
          }
        }
      }
    }
    return res;
  }
}
