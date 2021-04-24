import java.util.*;

class Program {
  public static List<List<Integer>> getPermutations(List<Integer> array) {
    // Write your code here.
    List<List<Integer>> res = new ArrayList<List<Integer>>();
    int n, N, L;

    if(array.size() > 0) {
      res.add(new ArrayList<Integer>());
    }
    for(Integer num: array) {
      L = res.size();
      while(L > 0) {
        L--;
        List<Integer> subList = res.remove(0);
        N = subList.size();
        for(n=0; n<=N; n++) {
          List<Integer> tmp = new ArrayList<Integer>(subList);
          tmp.add(n, num);
          res.add(tmp);
        }
      }
    }

    return res;
  }
}
