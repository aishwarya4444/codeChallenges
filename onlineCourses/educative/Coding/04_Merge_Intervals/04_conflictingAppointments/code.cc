// https://www.educative.io/courses/grokking-the-coding-interview/qVV79nGVgAG

using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class Interval {
 public:
  int start;
  int end;

  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};
// https://leetcode.com/problems/meeting-rooms/
class ConflictingAppointments {
 public:
  struct compareAscending {
    bool operator()(Interval &i1, Interval &i2) {
      return i1.start < i2.start;
    }
  };

  static bool canAttendAllAppointments(vector<Interval>& intervals) {
    // TODO: Write your code here
    int n, N=intervals.size();
    sort(intervals.begin(), intervals.end(), compareAscending());
    for(n=1; n<N; n++) {
      if(intervals[n-1].end >  intervals[n].start) {
        return false;
      }
    }
    return true;
  }
};

int main(int argc, char* argv[]) {
  vector<Interval> intervals = {{1, 4}, {2, 5}, {7, 9}};
  bool result = ConflictingAppointments::canAttendAllAppointments(intervals);
  cout << "Can attend all appointments: " << result << endl;

  intervals = {{6, 7}, {2, 4}, {8, 12}};
  result = ConflictingAppointments::canAttendAllAppointments(intervals);
  cout << "Can attend all appointments: " << result << endl;

  intervals = {{4, 5}, {2, 3}, {3, 6}};
  result = ConflictingAppointments::canAttendAllAppointments(intervals);
  cout << "Can attend all appointments: " << result << endl;
}
