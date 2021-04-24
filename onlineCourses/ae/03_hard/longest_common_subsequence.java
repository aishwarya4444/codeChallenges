import java.util.*;

class Program {
  public static List<Character> longestCommonSubsequence(String str1, String str2) {
    // Write your code here.
    int N1=str1.length(), N2=str2.length();
    int r, c;
    int[][] dp = new int[N1+1][N2+1];
    List<Character> res = new ArrayList<Character>();

    for(r=1; r<=N1; r++) {
      for(c=1; c<=N2; c++) {
        if(str1.charAt(r-1)==str2.charAt(c-1)) {
          dp[r][c] = 1+dp[r-1][c-1];
        } else {
          dp[r][c] = Math.max(dp[r][c-1], dp[r-1][c]);
        }
      }
    }

    r = N1;
    c = N2;
    // commented logic to build sequence also works
    // while(r>0 && c>0) {
    // 	if(str1.charAt(r-1)==str2.charAt(c-1)) {
    // 		res.add(0, str1.charAt(r-1));
    // 		r--;
    // 		c--;
    // 	} else if(dp[r-1][c]>dp[r][c-1]) {
    // 		r--;
    // 	} else {
    // 		c--;
    // 	}
    // }

    while(r>0 && c>0) {
      if(dp[r][c]==dp[r-1][c]) {
        r--;
      } else if(dp[r][c]==dp[r][c-1]) {
        c--;
      } else {
        res.add(0, str1.charAt(r-1));
        r--;
        c--;
      }
    }

    return res;
  }
}
