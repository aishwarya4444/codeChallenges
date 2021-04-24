import java.util.*;

/*
https://www.geeksforgeeks.org/a-search-algorithm/
https://www.educative.io/edpresso/what-is-the-a-star-algorithm
https://leetcode.com/problems/shortest-path-in-binary-matrix/discuss/313347/a-search-in-python
https://leetcode.com/problems/shortest-path-in-binary-matrix/discuss/313347/A*-search-in-Python/444210
https://leetcode.com/problems/minimum-moves-to-move-a-box-to-their-target-location/discuss/431061/A-star-search
*/
class Program {

  class Node {
    public String id;
    public Node prev;
    public int row;
    public int col;
    public int val;
    public int g;    /* distance from start */
    public int f;    /* distance to end */
    /* f = g + h (heuristic ... manhattan distance here) */

    Node(int row, int col, int val) {
      this.id = String.valueOf(row) + '-' + String.valueOf(col);
      this.prev = null;
      this.row = row;
      this.col = col;
      this.val = val;
      this.g = Integer.MAX_VALUE;
      this.f = Integer.MAX_VALUE;
    }
  }

  public int[][] aStarAlgorithm(int startRow, int startCol, int endRow, int endCol, int[][] graph) {
    // Write your code here.
    List<List<Node>> nodes = initNodes(graph);
    Queue<Node> minHeap = new PriorityQueue<Node>((n1, n2) -> {
      return n1.f - n2.f;
    });
    Node start = nodes.get(startRow).get(startCol);
    Node end = nodes.get(endRow).get(endCol);

    start.g = 0;
    start.f = start.g + calculateManhattanDistance(start, end);
    minHeap.add(start);

    while(minHeap.size() > 0) {
      Node minDistNode = minHeap.poll();
      if(minDistNode == end) {
        break;
      }
      for(Node neighbor: getNeighbors(minDistNode, nodes)) {
        if(neighbor.val == 1) {
          continue;
        }

        int tentativeDistToNeighbor = minDistNode.g + 1;
        if(tentativeDistToNeighbor >= neighbor.g) {
          continue;
        }

        neighbor.prev = minDistNode;
        neighbor.g = tentativeDistToNeighbor;
        neighbor.f = neighbor.g + calculateManhattanDistance(neighbor, end);

        if(minHeap.contains(neighbor)) {
          minHeap.remove(neighbor);
        }
        minHeap.add(neighbor);
      }
    }

    return reconstructPath(end);
  }

  private List<List<Node>> initNodes(int[][] graph) {
    List<List<Node>> nodes = new ArrayList<List<Node>>();
    int row, col;

    for(row=0; row<graph.length; row++) {
      List<Node> nodeList = new ArrayList<>();
      for(col=0; col<graph[row].length; col++) {
        nodeList.add(new Node(row, col, graph[row][col]));
      }
      nodes.add(nodeList);
    }

    return nodes;
  }

  private int calculateManhattanDistance(Node curr, Node end) {
    return Math.abs(curr.row - end.row) + Math.abs(curr.col - end.col);
  }

  private List<Node> getNeighbors(Node node, List<List<Node>> nodes) {
    int row = node.row, col = node.col;
    int ROWS = nodes.size(), COLS = nodes.get(0).size();
    List<Node> neighbors = new ArrayList<>();

    // DOWN
    if(row < ROWS-1) {
      neighbors.add(nodes.get(row+1).get(col));
    }

    // UO
    if(row > 0) {
      neighbors.add(nodes.get(row-1).get(col));
    }

    // LEFT
    if(col > 0) {
      neighbors.add(nodes.get(row).get(col-1));
    }

    // RIGHT
    if(col < COLS-1) {
      neighbors.add(nodes.get(row).get(col+1));
    }

    return neighbors;
  }

  private int[][] reconstructPath(Node node) {
    if(node.prev == null) {
      return new int[][]{};
    }

    Node current = node;
    List<List<Integer> > path = new ArrayList<>();

    while(current != null) {
      List<Integer> pathData = new ArrayList<>();
      pathData.add(current.row);
      pathData.add(current.col);
      path.add(0, pathData);
      current = current.prev;
    }

    int[][] res = new int[path.size()][2];
    for(int i=0; i<res.length; i++) {
      res[i][0] = path.get(i).get(0);
      res[i][1] = path.get(i).get(1);
    }

    return res;
  }
}
