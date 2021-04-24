import java.util.*;

/*
https://leetcode.com/problems/largest-1-bordered-square/discuss/1088780/BEATS-90-EASY-TO-UNDERSTAND-C%2B%2B
*/
class Program {
  public static boolean squareOfZeroes(List<List<Integer>> matrix) {
    // Write your code here.
    int res=0, len, w, h, l, L;
    int r, c, R=matrix.size(), C=matrix.get(0).size();
    int[][] height = new int[R+1][C+1];
    int[][] width = new int[R+1][C+1];

    for(r=1; r<=R; r++) {
      for(c=1; c<=C; c++) {
        if(matrix.get(r-1).get(c-1) == 0) {
          height[r][c] = 1+height[r-1][c];
          width[r][c] = 1+width[r][c-1];
        }
      }
    }

    for(r=1; r<=R; r++) {
      for(c=1; c<=C; c++) {
        L = Math.min(height[r][c], width[r][c]);
        for(l=1; l<=L; l++) {
          w = width[r-l+1][c];
          h = height[r][c-l+1];
          len = Math.min(w, h)>=l ? l : 0;
          res = Math.max(res, len);
        }
      }
    }

    return res>1;
  }
}
