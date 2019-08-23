// https://www.educative.io/courses/grokking-the-coding-interview/3jY0GKpPDxr

using namespace std;

#include <iostream>
#include <vector>

// https://leetcode.com/problems/circular-array-loop/

class CircularArrayLoop {
 public:
  static int findNext(const vector<int> &arr, int current, bool isForward) {
    bool directionForward = arr[current]>0;

    if(directionForward != isForward) {
      return -1;
    }

    int next = (current + arr[current] + arr.size()) % arr.size();

    if(next == current) {
      return -1;
    }

    return next;
  }

  static bool loopExists(const vector<int> &arr) {
    // TODO: Write your code here
    int index, slow, fast;
    bool isForward;
    for(index=0; index<arr.size(); index++) {
      if(arr[index] == 0) {
        continue;
      }
      slow = index;
      fast = index;
      isForward = arr[index]>0;
      while(slow!=-1 && fast!=-1) {
        slow = findNext(arr, slow, isForward);
        fast = findNext(arr, fast, isForward);
        if(fast != -1) {
          fast = findNext(arr, fast, isForward);
        }
        if(slow == fast) {
          break;
        }
      }
      if(slow != -1 && slow == fast) {
        return true;
      }
    }
    return false;
  }
};

int main(int argc, char *argv[]) {
  cout << CircularArrayLoop::loopExists(vector<int>{1, 2, -1, 2, 2}) << endl;
  cout << CircularArrayLoop::loopExists(vector<int>{2, 2, -1, 2}) << endl;
  cout << CircularArrayLoop::loopExists(vector<int>{2, 1, -1, -2}) << endl;
}
