import java.util.*;

class Program {

  public int maximumSumSubmatrix(int[][] matrix, int size) {
    // Write your code here.
    int r, c, R=matrix.length, C=matrix[0].length;
    int sum, maxSum=Integer.MIN_VALUE;
    int[][] dp = new int[R+1][C+1];

    for(r=0; r<R; r++) {
      for(c=0; c<C; c++) {
        dp[r+1][c+1] = matrix[r][c]+dp[r+1][c]+dp[r][c+1]-dp[r][c];
      }
    }

    for(r=size-1; r<R; r++) {
      for(c=size-1; c<C; c++) {
        sum = dp[r+1][c+1]-dp[r+1][c+1-size]-dp[r+1-size][c+1]+dp[r+1-size][c+1-size];
        maxSum = Math.max(maxSum, sum);
      }
    }

    return maxSum;
  }
}

/*
import java.util.*;

class Program {

  public int maximumSumSubmatrix(int[][] matrix, int size) {
    // Write your code here.
		// O(R*C) time | O(R*C) space
		int total, r, c, R=matrix.length, C=matrix[0].length;
		int[][] dp = createSumMatrix(matrix, R, C);
		int maxSubmatrixSum = Integer.MIN_VALUE;
		boolean touchesTopBorder, touchesLeftBorder;

		for(r=size-1; r<R; r++) {
			for(c=size-1; c<C; c++) {
				total = dp[r][c];

				touchesTopBorder = r<size;
				if(!touchesTopBorder) {
					total -= dp[r-size][c];
				}

				touchesLeftBorder = c<size;
				if(!touchesLeftBorder) {
					total -=dp[r][c-size];
				}

				if(!touchesLeftBorder && !touchesTopBorder) {
					total += dp[r-size][c-size];
				}

				maxSubmatrixSum = Math.max(total, maxSubmatrixSum);
			}
		}

    return maxSubmatrixSum;
  }

	public int[][] createSumMatrix(int[][] matrix, int R, int C) {
		int r, c;
		int[][] sums = new int[R][C];

		sums[0][0] = matrix[0][0];

		for(r=1; r<R; r++) {
			sums[r][0] = sums[r-1][0]+matrix[r][0];
		}

		for(c=1; c<C; c++) {
			sums[0][c] = sums[0][c-1]+matrix[0][c];
		}

		for(r=1; r<R; r++) {
			for(c=1; c<C; c++) {
				sums[r][c] = sums[r-1][c]+sums[r][c-1]+matrix[r][c]-sums[r-1][c-1];
			}
		}

		return sums;
	}
}

 */