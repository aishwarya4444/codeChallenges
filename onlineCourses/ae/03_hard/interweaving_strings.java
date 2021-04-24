import java.util.*;

class Program {
  public static boolean interweavingStrings(String one, String two, String three) {
    // Write your code here.
    int N1=one.length(), N2=two.length(), N3=three.length();
    int n1, n2, n3;

    if(N1+N2 != N3) {
      return false;
    }

    boolean[][] dp = new boolean[1+N1][1+N2];

    dp[0][0] = true;

    for(n1=1; n1<=N1; n1++) {
      dp[n1][0] = one.charAt(n1-1)==three.charAt(n1-1) && dp[n1-1][0];
    }

    for(n2=1; n2<=N2; n2++) {
      dp[0][n2] = two.charAt(n2-1)==three.charAt(n2-1) && dp[0][n2-1];
    }

    for(n1=1; n1<=N1; n1++) {
      for(n2=1; n2<=N2; n2++) {
        dp[n1][n2] = (one.charAt(n1-1)==three.charAt(n1+n2-1) && dp[n1-1][n2]) ||
            (two.charAt(n2-1)==three.charAt(n1+n2-1) && dp[n1][n2-1]);
      }
    }

    return dp[N1][N2];
  }
}
