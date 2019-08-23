// https://www.educative.io/courses/grokking-the-coding-interview/3jyVPKRA8yx

using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

class Interval {
 public:
  int start = 0;
  int end = 0;

  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class MergeIntervals {
 public:
  struct bigCompare {
    bool operator()(Interval &i1, Interval &i2) {
      return i1.start > i2.start;
    }
  };
  // https://leetcode.com/problems/merge-intervals/
  static vector<Interval> merge(vector<Interval> &intervals) {
    vector<Interval> mergedIntervals;
    // TODO: Write your code here
    // Interval minNode;
    priority_queue<Interval, vector<Interval>, bigCompare> minHeap;
    for(auto interval: intervals) {
      minHeap.push(interval);
    }
    while(minHeap.size()) {
      auto minNode = minHeap.top();
      minHeap.pop();
      if(minHeap.size() && minNode.end >= minHeap.top().start) {
        minNode.end = max(minNode.end, minHeap.top().end);
        minHeap.pop();
        minHeap.push(minNode);
      } else {
        mergedIntervals.push_back(minNode);
      }
    }
    return mergedIntervals;
  }
};

int main(int argc, char *argv[]) {
  vector<Interval> input = {{1, 3}, {2, 5}, {7, 9}};
  cout << "Merged intervals: ";
  for (auto interval : MergeIntervals::merge(input)) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;

  input = {{6, 7}, {2, 4}, {5, 9}};
  cout << "Merged intervals: ";
  for (auto interval : MergeIntervals::merge(input)) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;

  input = {{1, 4}, {2, 6}, {3, 5}};
  cout << "Merged intervals: ";
  for (auto interval : MergeIntervals::merge(input)) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;
}
