// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5590021564268544

using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class TaskScheduling {
  public:
    static bool isSchedulingPossible(int tasks, const vector<vector<int>>& prerequisites) {
      // TODO: Write your code here
      unordered_map<int, int> inDegree;
      unordered_map<int, vector<int> > graph;
      vector<int> children, schedule;
      queue<int> sources;
      int task;

      // initialize
      for(task=0; task<tasks; task++) {
        inDegree[task] = 0;
        graph[task] = vector<int>();
      }

      // populate graph
      for(auto prerequisite : prerequisites) {
        inDegree[prerequisite[1]]++;
        graph[prerequisite[0]].push_back(prerequisite[1]);
      }

      // find sources
      for(task=0; task<tasks; task++) {
        if(inDegree[task]==0) {
          sources.push(task);
        }
      }

      // level order traversal
      while(sources.size()) {
        task = sources.front();
        sources.pop();
        schedule.push_back(task);
        children = graph[task];
        for(auto child: children) {
          inDegree[child]--;
          if(inDegree[child]==0) {
            sources.push(child);
          }
        }
      }

      return schedule.size()==tasks ? true : false;
    }
};

int main(int argc, char* argv[]) {
  bool result = TaskScheduling::isSchedulingPossible(
      3, vector<vector<int>>{vector<int>{0, 1}, vector<int>{1, 2}});
  cout << "Tasks execution possible: " << result << endl;

  result = TaskScheduling::isSchedulingPossible(
      3, vector<vector<int>>{vector<int>{0, 1}, vector<int>{1, 2}, vector<int>{2, 0}});
  cout << "Tasks execution possible: " << result << endl;

  result = TaskScheduling::isSchedulingPossible(
      6, vector<vector<int>>{vector<int>{2, 5}, vector<int>{0, 5}, vector<int>{0, 4},
                             vector<int>{1, 4}, vector<int>{3, 2}, vector<int>{1, 3}});
  cout << "Tasks execution possible: " << result << endl;
}
