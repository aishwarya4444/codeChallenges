import java.util.*;

class Program {
  public static List<List<Integer>> knapsackProblem(int[][] items, int capacity) {
    // Write your code here.
    // Replace the code below.
    int I=items.length, C=capacity;
    int i, c, weight, profit;
    int[][] dp = new int[I+1][C+1];

    for(i=1; i<=I; i++) {
      for(c=0; c<=C; c++) {
        profit = items[i-1][0];
        weight = items[i-1][1];
        if(c>=weight) {
          dp[i][c] = profit + dp[i-1][c-weight];
        }
        dp[i][c] = Math.max(dp[i][c], dp[i-1][c]);
      }
    }

    return getSequence(I, C, dp, items, dp[I][C]);
  }

  private static List<List<Integer>> getSequence(int i, int c, int[][] dp, int[][] items, int maxProfit) {
    List<List<Integer>> result = new ArrayList<List<Integer>>();
    List<Integer> sequence = new ArrayList<Integer>();

    result.add(Arrays.asList(dp[i][c]));

    while(i>0 && c>0) {
      if(dp[i][c] != dp[i-1][c]) {
        sequence.add(0, i-1);
        c -= items[i-1][1];
      }
      i--;
    }

    result.add(sequence);
    return result;
  }
}
