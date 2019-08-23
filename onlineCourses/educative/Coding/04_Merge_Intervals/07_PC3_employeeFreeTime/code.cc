// https://www.educative.io/courses/grokking-the-coding-interview/YQykDmBnvB0

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

class EmployeeFreeTime {
 public:
  struct compareStart {
    bool operator()(const Interval &i1, const Interval &i2) {
      return i1.start > i2.start;
    }
  };

  // https://leetcode.com/problems/employee-free-time/

  static vector<Interval> findEmployeeFreeTime(const vector<vector<Interval>> &schedule) {
    vector<Interval> result;
    // TODO: Write your code here
    priority_queue<Interval, vector<Interval>, compareStart> minHeap;
    vector<Interval> overlap, free;
    int n;
    for(n=0; n<schedule.size(); n++) {
      for(auto time : schedule[n]) {
        minHeap.push(time);
      }
    }
    while(minHeap.size()) {
      auto time = minHeap.top();
      minHeap.pop();
      if(minHeap.size() && time.end>=minHeap.top().start) {
        time.end = max(time.end, minHeap.top().end);
        minHeap.pop();
        minHeap.push(time);
      } else {
        overlap.push_back(time);
      }
    }
    for(n=1; n<overlap.size(); n++) {
      free.push_back({overlap[n-1].end, overlap[n].start});
    }
    return free;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<Interval>> input = {{{1, 3}, {5, 6}}, {{2, 3}, {6, 8}}};
  vector<Interval> result = EmployeeFreeTime::findEmployeeFreeTime(input);
  cout << "Free intervals: ";
  for (auto interval : result) {
    cout << "[" << interval.start << ", " << interval.end << "] ";
  }
  cout << endl;

  input = {{{1, 3}, {9, 12}}, {{2, 4}}, {{6, 8}}};
  result = EmployeeFreeTime::findEmployeeFreeTime(input);
  cout << "Free intervals: ";
  for (auto interval : result) {
    cout << "[" << interval.start << ", " << interval.end << "] ";
  }
  cout << endl;

  input = {{{1, 3}}, {{2, 4}}, {{3, 5}, {7, 9}}};
  result = EmployeeFreeTime::findEmployeeFreeTime(input);
  cout << "Free intervals: ";
  for (auto interval : result) {
    cout << "[" << interval.start << ", " << interval.end << "] ";
  }
}
