import java.util.*;

class Program {
  public static List<List<Integer>> powerset(List<Integer> array) {
    // Write your code here.
    List<List<Integer>> res = new ArrayList<>();
    int n, N;

    res.add(new ArrayList<>());
    for(Integer num: array) {
      N = res.size();
      for(n=0; n<N; n++) {
        List<Integer> list = new ArrayList<Integer>(res.get(n));
        list.add(num);
        res.add(list);
      }
    }

    return res;
  }
}
