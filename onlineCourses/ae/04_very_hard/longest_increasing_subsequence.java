import java.util.*;

class Program {
  public static List<Integer> longestIncreasingSubsequence(int[] array) {
    // Write your code here.

    int i, j, N=array.length, len=1, idx=0;
    int[] dp = new int[N];
    List<Integer> res = new ArrayList<>();

    Arrays.fill(dp, 1);

    for(i=1; i<N; i++) {
      for(j=0; j<i; j++) {
        if(array[i]>array[j] && dp[i]<dp[j]+1) {
          dp[i] = 1+dp[j];
          if(len<dp[i]) {
            len = dp[i];
            idx = i;
          }
        }
      }
    }

    while(len>0) {
      if(dp[idx]==len) {
        len--;
        res.add(0, array[idx]);
      }
      idx--;
    }
    return res;
  }
}
