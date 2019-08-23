// https://www.educative.io/courses/grokking-the-coding-interview/xVoBRZz7RwP

using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class Meeting {
 public:
  int start = 0;
  int end = 0;

  Meeting(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class MinimumMeetingRooms {
 public:
  struct compareStart {
    bool operator()(const Meeting &m1, const Meeting &m2) {
      return m1.start < m2.start;
    }
  };

  struct compareEnd {
    bool operator()(const Meeting &m1, const Meeting &m2) {
      return m1.end > m2.end;
    }
  };

  // https://leetcode.com/problems/meeting-rooms-ii/
  static int findMinimumMeetingRooms(vector<Meeting> &meetings) {
    // TODO: Write your code here
    int rooms=0;
    priority_queue<Meeting, vector<Meeting>, compareEnd> minHeap;
    sort(meetings.begin(), meetings.end(), compareStart());
    for(auto meeting : meetings) {
      while(minHeap.size() && minHeap.top().end<=meeting.start) {
        minHeap.pop();
      }
      minHeap.push(meeting);
      rooms = max((int)minHeap.size(), rooms);
    }
    return rooms;
  }
};

int main(int argc, char *argv[]) {
  vector<Meeting> input = {{4, 5}, {2, 3}, {2, 4}, {3, 5}};
  int result = MinimumMeetingRooms::findMinimumMeetingRooms(input);
  cout << "Minimum meeting rooms required: " << result << endl;

  input = {{1, 4}, {2, 5}, {7, 9}};
  result = MinimumMeetingRooms::findMinimumMeetingRooms(input);
  cout << "Minimum meeting rooms required: " << result << endl;

  input = {{6, 7}, {2, 4}, {8, 12}};
  result = MinimumMeetingRooms::findMinimumMeetingRooms(input);
  cout << "Minimum meeting rooms required: " << result << endl;

  input = {{1, 4}, {2, 3}, {3, 6}};
  result = MinimumMeetingRooms::findMinimumMeetingRooms(input);
  cout << "Minimum meeting rooms required: " << result << endl;

  input = {{4, 5}, {2, 3}, {2, 4}, {3, 5}};
  result = MinimumMeetingRooms::findMinimumMeetingRooms(input);
  cout << "Minimum meeting rooms required: " << result << endl;
}
