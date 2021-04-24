import java.util.*;

class Program {
  public static List<List<Integer>> maxSumIncreasingSubsequence(int[] array) {
    // Write your code here.
    int i, j, N=array.length, maxIdx=0;
    int[] dp = new int[N];
    int[] seq = new int[N];

    Arrays.fill(seq, Integer.MIN_VALUE);
    dp = array.clone();

    for(i=1; i<N; i++) {
      for(j=0; j<i; j++) {
        if(array[i]>array[j] && dp[i]<=array[i]+dp[j]) {
          dp[i] = array[i]+dp[j];
          seq[i] = j;
        }
      }

      if(dp[i] >= dp[maxIdx]) {
        maxIdx = i;
      }
    }

    return getSequence(array, seq, maxIdx, dp[maxIdx]);
  }

  public static List<List<Integer>> getSequence(int[] arr, int[] seq, int idx, int sum) {
    List<List<Integer>> res = new ArrayList<>();

    res.add(new ArrayList<>());
    res.add(new ArrayList<>());

    while(idx != Integer.MIN_VALUE) {
      res.get(1).add(0, arr[idx]);
      idx = seq[idx];
    }
    res.get(0).add(sum);

    return res;
  }
}
