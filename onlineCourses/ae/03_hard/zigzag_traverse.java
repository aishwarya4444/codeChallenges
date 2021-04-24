import java.util.*;

class Program {
  public static List<Integer> zigzagTraverse(List<List<Integer>> array) {
    // Write your code here.
		/*
		https://leetcode.com/problems/diagonal-traverse/discuss/985788/simple-java-w-detailed-video-solution
		*/
    List<Integer> res = new ArrayList<Integer>();
    int r, c, R=array.size(), C=array.get(0).size();
    int diag=0, D=R+C;

    for(diag=0; diag<D; diag++) {
      if(diag%2 == 0) { // down
        for(c=Math.min(diag, C-1); c>=0; c--) {
          r = diag-c;
          if(r>=R) {
            continue;
          }
          res.add(array.get(r).get(c));
        }
      } else { // up
        for(r=Math.min(diag, R-1); r>=0; r--) {
          c = diag-r;
          if(c>=C) {
            continue;
          }
          res.add(array.get(r).get(c));
        }
      }

    }

    return res;
  }
}
