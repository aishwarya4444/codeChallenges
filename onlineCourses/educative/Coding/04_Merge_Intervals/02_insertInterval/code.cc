// https://www.educative.io/courses/grokking-the-coding-interview/3jKlyNMJPEM

using namespace std;

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

// https://leetcode.com/problems/insert-interval/

// O(N lg N) solution

class InsertInterval {
 public:
  struct bigCompare {
    bool operator()(Interval &i1, Interval &i2) {
      return i1.start > i2.start;
    }
  };

  static vector<Interval> insert(const vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> mergedIntervals;
    // TODO: Write your code here
    priority_queue<Interval, vector<Interval>, bigCompare> minHeap;
    for(auto interval: intervals) {
      minHeap.push(interval);
    }
    minHeap.push(newInterval);
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
  vector<Interval> input = {{1, 3}, {5, 7}, {8, 12}};
  cout << "Intervals after inserting the new interval: ";
  for (auto interval : InsertInterval::insert(input, {4, 6})) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;

  cout << "Intervals after inserting the new interval: ";
  for (auto interval : InsertInterval::insert(input, {4, 10})) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;

  input = {{2, 3}, {5, 7}};
  cout << "Intervals after inserting the new interval: ";
  for (auto interval : InsertInterval::insert(input, {1, 4})) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;
}

/*
better solution O(n) time
using namespace std;

#include <iostream>
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

class InsertInterval {
 public:
  static vector<Interval> insert(const vector<Interval> &intervals, Interval newInterval) {
    if (intervals.empty() || intervals.empty()) {
      return vector<Interval>{newInterval};
    }

    vector<Interval> mergedIntervals;

    int i = 0;
    // skip (and add to output) all intervals that come before the 'newInterval'
    while (i < intervals.size() && intervals[i].end < newInterval.start) {
      mergedIntervals.push_back(intervals[i++]);
    }

    // merge all intervals that overlap with 'newInterval'
    while (i < intervals.size() && intervals[i].start <= newInterval.end) {
      newInterval.start = min(intervals[i].start, newInterval.start);
      newInterval.end = max(intervals[i].end, newInterval.end);
      i++;
    }

    // insert the newInterval
    mergedIntervals.push_back(newInterval);

    // add all the remaining intervals to the output
    while (i < intervals.size()) {
      mergedIntervals.push_back(intervals[i++]);
    }

    return mergedIntervals;
  }
};

int main(int argc, char *argv[]) {
  vector<Interval> input = {{1, 3}, {5, 7}, {8, 12}};
  cout << "Intervals after inserting the new interval: ";
  for (auto interval : InsertInterval::insert(input, {4, 6})) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;

  cout << "Intervals after inserting the new interval: ";
  for (auto interval : InsertInterval::insert(input, {4, 10})) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;

  input = {{2, 3}, {5, 7}};
  cout << "Intervals after inserting the new interval: ";
  for (auto interval : InsertInterval::insert(input, {1, 4})) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;
}
*/
