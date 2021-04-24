import java.util.*;

class Program {

  class Pair {
    public int task;
    public int index;
    Pair(int t, int i) {
      task = t;
      index = i;
    }
  }

  public ArrayList<ArrayList<Integer>> taskAssignment(int k, ArrayList<Integer> tasks) {
    // Write your code here.
    List<Pair> taskList = new ArrayList<Pair>();
    ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
    int start, end;

    for(start=0; start<2*k; start++) {
      taskList.add(new Pair(tasks.get(start), start));
    }

    Collections.sort(taskList, new Comparator<Pair>() {
      @Override
      public int compare(final Pair p1, final Pair p2) {
        if(p1.task < p2.task) {
          return 1;
        } else if(p1.task > p2.task) {
          return -1;
        } else {
          return 0;
        }
      }
    });

    for(start=0, end=2*k-1; start<end; start++, end--) {
      ArrayList<Integer> tmp = new ArrayList<Integer>();
      tmp.add(taskList.get(start).index);
      tmp.add(taskList.get(end).index);
      result.add(tmp);
    }

    return result;
  }
}
