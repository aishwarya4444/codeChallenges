import java.util.*;

class Program {

  public int numberOfWaysToTraverseGraph(int width, int height) {
    // Write your code here.
    int[][] dp = new int[width][height];
    int r, c;

    for(r=1; r<width; r++) {
      dp[r][0] = 1;
    }

    for(c=1; c<height; c++) {
      dp[0][c] = 1;
    }

    for(r=1; r<width; r++) {
      for(c=1; c<height; c++) {
        dp[r][c] = dp[r][c-1]+dp[r-1][c];
      }
    }

    return dp[width-1][height-1];
  }
}
