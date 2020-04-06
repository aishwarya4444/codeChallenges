// https://www.educative.io/collection/page/5668639101419520/5671464854355968/6005247778488320

using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

// https://leetcode.com/problems/task-scheduler/
// without storing char also we can do

class TaskScheduler {
 public:
  struct compareBig {
    bool operator()(pair<char, int> &p1, pair<char, int> &p2) {
      return p1.second < p2.second;
    }
  };

  static int scheduleTasks(vector<char> &tasks, int k) {
    int intervalCount = 0;
    // TODO: Write your code here
    pair<char, int> dummy(0,0), node;
    unordered_map<char, int> m;
    priority_queue<pair<char, int>, vector<pair<char, int>>, compareBig> maxHeap;
    vector<pair<char, int>> waitList;
    int n;

    // populate map
    for(auto task: tasks) {
      m[task]++;
    }

    // populate heap
    for(auto entry: m) {
      maxHeap.push(entry);
    }

    while(maxHeap.size()) {
      n = k+1;
      for(; n>0 && maxHeap.size(); n--) {
        node = maxHeap.top();
        maxHeap.pop();
        node.second--;
        intervalCount++;
        if(node.second) {
          waitList.push_back(node);
        }
      }

      for(auto it=waitList.begin(); it!=waitList.end(); it++) {
        maxHeap.push(*it);
      }

      if(maxHeap.size()) {
        intervalCount += n;
      }

      waitList.clear();
    }
    return intervalCount;
  }
};

int main(int argc, char *argv[]) {
  vector<char> tasks = {'a', 'a', 'a'};
  cout << "Minimum intervals needed to execute all tasks: "
       << TaskScheduler::scheduleTasks(tasks, 1) << endl;

  tasks = vector<char>{'a', 'b', 'a'};
  cout << "Minimum intervals needed to execute all tasks: "
       << TaskScheduler::scheduleTasks(tasks, 3) << endl;
}
