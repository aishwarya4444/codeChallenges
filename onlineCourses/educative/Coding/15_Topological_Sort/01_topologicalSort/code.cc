// https://www.educative.io/collection/page/5668639101419520/5671464854355968/6010387461832704

using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class TopologicalSort {
  public:
    static vector<int> sort(int vertices, const vector<vector<int>>& edges) {
      vector<int> sortedOrder;
      // TODO: Write your code here
      unordered_map<int, vector<int> > graph;
      unordered_map<int, int> inDegree;
      vector<int> children;
      queue<int> level;
      int v;

      // initialize
      for(v=0; v<vertices; v++) {
        inDegree[v] = 0;
        graph[v] = vector<int>();
      }

      // populate in degree and graph
      for(auto edge : edges) {
        // source vertices will have 0 in degree
        inDegree[edge[1]]++;
        // graph is adjacency list
        graph[edge[0]].push_back(edge[1]);
      }

      // vertices with 0 in degree are SOURCE vertices for us
      for(v=0; v<vertices; v++) {
        if(inDegree[v]==0) {
          level.push(v);
        }
      }

      // level order traversal
      while(level.size()) {
        v = level.front();
        level.pop();
        sortedOrder.push_back(v);
        children = graph[v];
        for(auto child : children) {
          inDegree[child]--;
          if(inDegree[child]==0) {
            level.push(child);
          }
        }
      }

      // graph has cycle
      if(sortedOrder.size() != vertices) {
        return vector<int>();
      }

      return sortedOrder;
    }
};

int main(int argc, char* argv[]) {
  vector<int> result =
      TopologicalSort::sort(4, vector<vector<int>>{vector<int>{3, 2}, vector<int>{3, 0},
                                                   vector<int>{2, 0}, vector<int>{2, 1}});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = TopologicalSort::sort(
      5, vector<vector<int>>{vector<int>{4, 2}, vector<int>{4, 3}, vector<int>{2, 0},
                             vector<int>{2, 1}, vector<int>{3, 1}});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = TopologicalSort::sort(
      7, vector<vector<int>>{vector<int>{6, 4}, vector<int>{6, 2}, vector<int>{5, 3},
                             vector<int>{5, 4}, vector<int>{3, 0}, vector<int>{3, 1},
                             vector<int>{3, 2}, vector<int>{4, 1}});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}
