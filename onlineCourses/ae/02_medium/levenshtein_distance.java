import java.util.*;

class Program {
  public static int levenshteinDistance(String str1, String str2) {
    // Write your code here.
    int row, col, ROWS = str1.length(), COLS = str2.length();
    int[][] dp = new int[ROWS+1][COLS+1];

    for(row=1; row<=ROWS; row++) {
      dp[row][0] = row;
    }
    for(col=1; col<=COLS; col++) {
      dp[0][col] = col;
    }

    for(row=1; row<=ROWS; row++) {
      for(col=1; col<=COLS; col++) {
        if(str1.charAt(row-1) == str2.charAt(col-1)) {
          dp[row][col] = dp[row-1][col-1];
        } else {
          dp[row][col] = 1 + Math.min(dp[row-1][col], Math.min(dp[row-1][col-1], dp[row][col-1]));
        }
      }
    }
    return dp[ROWS][COLS];
  }
}
