import java.util.*;

class Node {
  public int val;
  public int row;
  public int col;
  Node(int v, int r, int c) {
    val = v;
    row = r;
    col = c;
  }
}

class Program {
  public static List<Integer> mergeSortedArrays(List<List<Integer>> arrays) {
    // Write your code here.
    Queue<Node> minHeap = new PriorityQueue<Node>((n1, n2) -> {
      return n1.val-n2.val;
    });
    List<Integer> res = new ArrayList<>();
    int row, col, R=arrays.size(), C;

    for(row=0, col=0; row<R; row++) {
      minHeap.add(new Node(arrays.get(row).get(col), row, col));
    }

    while(minHeap.size() > 0) {
      Node tmp = minHeap.poll();
      res.add(tmp.val);
      row = tmp.row;
      col = tmp.col;
      C = arrays.get(row).size();
      if(col != C-1) {
        minHeap.add(new Node(arrays.get(row).get(col+1), row, col+1));
      }
    }

    return res;
  }
}
