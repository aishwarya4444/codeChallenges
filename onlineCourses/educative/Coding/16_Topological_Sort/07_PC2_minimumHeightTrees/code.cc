// https://www.educative.io/collection/page/5668639101419520/5671464854355968/6545337986580480

using namespace std;

#include <deque>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <queue>

// https://leetcode.com/problems/minimum-height-trees/

class MinimumHeightTrees {
 public:
  static vector<int> findTrees(int nodes, vector<vector<int>>& edges) {
    vector<int> minHeightTrees;
    // TODO: Write your code here
    unordered_map<int, vector<int> > graph;
    unordered_map<int, int> indegree;
    queue<int> leaves;
    vector<int> children;
    int i, L, node;

    // 0 nodes
    if(nodes == 0) {
      return minHeightTrees;
    }

    // 1 node
    if(nodes == 1) {
      minHeightTrees.push_back(0);
      return minHeightTrees;
    }

    // init graph
    for(i=0; i<nodes; i++) {
      indegree[i] = 0;
      graph[i] = vector<int>();
    }

    // populate graph
    for(auto edge: edges) {
      indegree[edge[0]]++;
      indegree[edge[1]]++;
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }

    // find leaves
    for(auto entry: indegree) {
      if(entry.second == 1) {
        leaves.push(entry.first);
      }
    }

    // bfs
    while(nodes > 2) {
      L = leaves.size();
      nodes -= L;
      for(i=0; i<L; i++) {
        node = leaves.front();
        leaves.pop();
        children = graph[node];
        for(auto child: children) {
          indegree[child]--;
          if(indegree[child] == 1) {
            leaves.push(child);
          }
        }
      }
    }

    while(leaves.size()) {
      minHeightTrees.push_back(leaves.front());
      leaves.pop();
    }
    return minHeightTrees;
  }
};

int main(int argc, char* argv[]) {
  vector<vector<int>> vec = {{0, 1}, {1, 2}, {1, 3}, {2, 4}};
  vector<int> result = MinimumHeightTrees::findTrees(5, vec);
  cout << "Roots of MHTs: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  vec = {{0, 1}, {0, 2}, {2, 3}};
  result = MinimumHeightTrees::findTrees(4, vec);
  cout << "Roots of MHTs: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  vec = {{0, 1}, {1, 2}, {1, 3}};
  result = MinimumHeightTrees::findTrees(4, vec);
  cout << "Roots of MHTs: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}
