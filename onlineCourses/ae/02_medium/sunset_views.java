import java.util.*;

class Program {

  public ArrayList<Integer> sunsetViews(int[] buildings, String direction) {
    // Write your code here.
    if(direction.equals("WEST")) {
      return leftToRight(buildings);
    } else {
      return rightToLeft(buildings);
    }
  }

  private static ArrayList<Integer> leftToRight(int[] buildings) {
    ArrayList<Integer> res = new ArrayList<Integer>();
    int n, N=buildings.length, height = 0;

    for(n=0; n<N; n++) {
      if(height < buildings[n]) {
        res.add(n);
      }
      height = Math.max(height, buildings[n]);
    }

    return res;
  }



  private static ArrayList<Integer> rightToLeft(int[] buildings) {
    ArrayList<Integer> res = new ArrayList<Integer>();
    int n, N=buildings.length, height = 0;

    for(n=N-1; n>=0; n--) {
      if(height < buildings[n]) {
        res.add(0, n);
      }
      height = Math.max(height, buildings[n]);
    }

    return res;
  }
}
