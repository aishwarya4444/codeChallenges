import java.util.*;

class Program {
  public static List<Integer> spiralTraverse(int[][] array) {
    // Write your code here.
    List<Integer> result = new ArrayList<>();
    int row, r=0, R=array.length-1;
    int col, c=0, C=array[0].length-1;

    while(r<=R && c<=C) {
      for(col=c; col<=C; col++) {
        result.add(array[r][col]);
      }

      for(row=r+1; row<=R; row++) {
        result.add(array[row][C]);
      }

      for(col=C-1; col>=c; col--) {
        if(r==R) {
          break;
        }
        result.add(array[R][col]);
      }

      for(row=R-1; row>r; row--) {
        if(c==C) {
          break;
        }
        result.add(array[row][c]);
      }

      r++;
      c++;
      R--;
      C--;
    }

    return result;
  }
}
