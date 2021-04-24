import java.util.*;

class Program {
  class Pair {
    public int u;
    public int dist;
    Pair(int _u, int _dist) {
      u = _u;
      dist = _dist;
    }
  }

  public int[] dijkstrasAlgorithm(int start, int[][][] edges) {
    // Write your code here.
    int u, v, w, V = edges.length;
    Queue<Pair> minHeap = new PriorityQueue<Pair>((p1, p2) -> {
      return p1.dist - p2.dist;
    });
    int[] dist = new int[V];

    Arrays.fill(dist, Integer.MAX_VALUE);
    dist[start] = 0;
    minHeap.add(new Pair(start, dist[start]));

    while(minHeap.size() > 0) {
      Pair tmp = minHeap.poll();
      u = tmp.u;
      for(int[] edge: edges[u]) {
        v = edge[0];
        w = edge[1];
        if(dist[v] > dist[u]+w) {
          dist[v] = dist[u]+w;
          minHeap.add(new Pair(v, dist[v]));
        }
      }
    }

    for(v=0; v<V; v++) {
      if(dist[v] == Integer.MAX_VALUE) {
        dist[v] = -1;
      }
    }

    return dist;
  }

}
