// https://www.educative.io/collection/page/5668639101419520/5671464854355968/4994209155121152

using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

class AllTaskSchedulingOrders {
 public:
  static void printAllOrders(unordered_map<int, vector<int> > &graph,
    unordered_map<int, int> &indegree,
    vector<int> &sources,
    vector<int> &order) {

    if(sources.empty()) {
      if(indegree.size() == order.size()) {
        for(auto vertex: order) {
          cout<<vertex<<' ';
        }
        cout<<endl;
      }
      return;
    }

    for(auto parent: sources) {
      order.push_back(parent);
      vector<int> nextSources = sources;
      nextSources.erase(find(nextSources.begin(), nextSources.end(), parent));

      vector<int> children = graph[parent];
      for(auto child: children) {
        indegree[child]--;
        if(indegree[child] == 0) {
          nextSources.push_back(child);
        }
      }

      printAllOrders(graph, indegree, nextSources, order);

      order.erase(find(order.begin(), order.end(), parent));
      for(auto child: children) {
        indegree[child]++;
      }
    }
  }

  static void printOrders(int tasks, vector<vector<int>> &prerequisites) {
    vector<int> sortedOrder;
    // TODO: Write your code here
    unordered_map<int, vector<int> > graph;
    unordered_map<int, int> indegree;
    int i, parent, child;
    vector<int> sources, order;

    // init graph
    for(i=0; i<tasks; i++) {
      indegree[i] = 0;
      graph[i] = vector<int>();
    }

    // populate graph
    for(auto req: prerequisites) {
      parent = req[0];
      child = req[1];
      indegree[child]++;
      graph[parent].push_back(child);
    }

    // populate indegree
    for(auto entry: indegree) {
      if(entry.second == 0) {
        sources.push_back(entry.first);
      }
    }

    // print all possible orders
    printAllOrders(graph, indegree, sources, order);
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> vec = {{0, 1}, {1, 2}};
  AllTaskSchedulingOrders::printOrders(3, vec);
  cout << endl;

  vec = {{3, 2}, {3, 0}, {2, 0}, {2, 1}};
  AllTaskSchedulingOrders::printOrders(4, vec);
  cout << endl;

  vec = {{2, 5}, {0, 5}, {0, 4}, {1, 4}, {3, 2}, {1, 3}};
  AllTaskSchedulingOrders::printOrders(6, vec);
  cout << endl;
}
