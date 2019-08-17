// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5068726468608000

using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class Interval {
 public:
  int start = 0;
  int end = 0;

  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

// https://leetcode.com/problems/find-right-interval/
// has binary search solution also .. check once

class NextInterval {
 public:
  struct compareLess {
    bool operator()(const pair<int, int> &p1, const pair<int, int> &p2) {
      return p1.first < p2.first;
    }
  };

  static vector<int> findNextInterval(const vector<Interval> &intervals) {
    int n = intervals.size();
    vector<int> result(n);
    // TODO: Write your code here
    priority_queue<pair<int, int>, vector<pair<int, int> >, compareLess > maxStartHeap, maxEndHeap;
    int i;
    pair<int, int> startNode, endNode;
    for(i=0; i<n; i++) {
      maxStartHeap.push(make_pair(intervals[i].start, i));
      maxEndHeap.push(make_pair(intervals[i].end, i));
    }
    while(maxEndHeap.size()) {
      endNode = maxEndHeap.top();
      maxEndHeap.pop();

      startNode = maxStartHeap.top();
      maxStartHeap.pop();
      if(endNode.first <= startNode.first) {
        while(endNode.first <= maxStartHeap.top().first) {
          startNode = maxStartHeap.top();
          maxStartHeap.pop();
        }
        result[endNode.second] = startNode.second;
      } else {
        result[endNode.second] = -1;
      }
      maxStartHeap.push(startNode);
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  vector<Interval> intervals = {{2, 3}, {3, 4}, {5, 6}};
  vector<int> result = NextInterval::findNextInterval(intervals);
  cout << "Next interval indices are: ";
  for (auto index : result) {
    cout << index << " ";
  }
  cout << endl;

  intervals = {{3, 4}, {1, 5}, {4, 6}};
  result = NextInterval::findNextInterval(intervals);
  cout << "Next interval indices are: ";
  for (auto index : result) {
    cout << index << " ";
  }
}
