import java.util.*;

class Program {

  public boolean cycleInGraph(int[][] edges) {
    // Write your code here.
    int visited=0, N = edges.length;
    int[] indegree = new int[N];
    Queue<Integer> src = new LinkedList<>();

    for(int[] edge: edges) {
      for(int v: edge) {
        indegree[v]++;
      }
    }

    for(int u=0; u<N; u++) {
      if(indegree[u] == 0) {
        src.add(u);
      }
    }

    while(src.size() != 0) {
      int u = src.poll();
      visited++;

      for(int v: edges[u]) {
        indegree[v]--;
        if(indegree[v] == 0) {
          src.add(v);
        }
      }
    }

    return visited!=N;
  }
}
