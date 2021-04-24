import java.util.*;

class Program {
  public static int[] searchInSortedMatrix(int[][] matrix, int target) {
    // Write your code here.
    int row, col, R=matrix.length, C=matrix[0].length;

    row = 0;
    col = C-1;

    while(row<R && col>=0) {
      if(matrix[row][col] == target) {
        return new int[] {row, col};
      }
      if(matrix[row][col]<target) {
        row++;
      } else {
        col--;
      }
    }
    return new int[] {-1, -1};
  }
}
