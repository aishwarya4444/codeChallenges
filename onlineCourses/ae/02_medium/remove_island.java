import java.util.*;

class Program {
  private final int[][] dirs = {{-1,0}, {0,1}, {1,0}, {0,-1}};
  private int R;
  private int C;

  private void dfs(int row, int col, int[][] matrix) {
    if(row<0 || row>=R || col<0 || col>=C) {
      return;
    }

    if(matrix[row][col] != 1) {
      return;
    }

    matrix[row][col] = 2;
    for(int[] dir: dirs) {
      dfs(row+dir[0], col+dir[1], matrix);
    }
  }

  public int[][] removeIslands(int[][] matrix) {
    // Write your code here.
    int row, col;
    R = matrix.length;
    C = matrix[0].length;

    for(row=0; row<R; row++) {
      for(col=0; col<C; col++) {
        if(row==0 || col==0 || row==R-1 || col==C-1) {
          if(matrix[row][col]==1) {
            // label all border connected 1 as 2
            dfs(row, col, matrix);
          }
        }
      }
    }

    for(row=0; row<R; row++) {
      for(col=0; col<C; col++) {
        if(matrix[row][col] == 2) {
          matrix[row][col] = 1;
        } else {
          matrix[row][col] = 0;
        }
      }
    }

    return matrix;
  }
}
