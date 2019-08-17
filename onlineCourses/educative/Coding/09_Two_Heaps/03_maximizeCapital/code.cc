// https://www.educative.io/collection/page/5668639101419520/5671464854355968/4891120511221760

using namespace std;

#include <iostream>
#include <queue>
#include <vector>

// https://leetcode.com/problems/ipo/

class MaximizeCapital {
 public:
  struct greaterCompare {
    bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) {
      return p1.first > p2.first;
    }
  };

  struct smallerCompare {
    bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) {
      return p1.second < p2.second;
    }
  };

  static int findMaximumCapital(const vector<int> &capital, const vector<int> &profits,
                                int numberOfProjects, int initialCapital) {
    // TODO: Write your code here
    priority_queue<pair<int, int>, vector<pair<int, int> >, greaterCompare> minHeap;
    priority_queue<pair<int, int>, vector<pair<int, int> >, smallerCompare> maxHeap;
    int n, N=capital.size();
    for(n=0; n<N; n++) {
      minHeap.push(make_pair(capital[n], profits[n]));
    }
    while(numberOfProjects--) {
      while(minHeap.size() && initialCapital >= minHeap.top().first) {
        maxHeap.push(minHeap.top());
        minHeap.pop();
      }
      if(maxHeap.size()) {
        initialCapital += maxHeap.top().second;
        maxHeap.pop();
      }
    }
    return initialCapital;
  }
};

int main(int argc, char *argv[]) {
  int result =
      MaximizeCapital::findMaximumCapital(vector<int>{0, 1, 2}, vector<int>{1, 2, 3}, 2, 1);
  cout << "Maximum capital: " << result << endl;
  result =
      MaximizeCapital::findMaximumCapital(vector<int>{0, 1, 2, 3}, vector<int>{1, 2, 3, 5}, 3, 0);
  cout << "Maximum capital: " << result << endl;
}
