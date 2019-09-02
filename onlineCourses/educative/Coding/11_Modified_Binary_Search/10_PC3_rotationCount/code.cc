// https://www.educative.io/courses/grokking-the-coding-interview/7nPmB8mZ6vj

using namespace std;

#include <iostream>
#include <vector>

// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

class RotationCountOfRotatedArray {
 public:
  static int countRotations(const vector<int>& nums) {
    // TODO: Write your code here
    int l=0, m, r=nums.size()-1;
    while(l<r) {
      m = l+(r-l)/2;
      if(nums[m] < nums[r]) {
        r = m;
      } else if(nums[m] > nums[r]) {
        l = m+1;
      } else {
        r--;
      }
    }
    return l;
  }
};

int main(int argc, char* argv[]) {
  cout << RotationCountOfRotatedArray::countRotations(vector<int>{10, 15, 1, 3, 8}) << endl;
  cout << RotationCountOfRotatedArray::countRotations(vector<int>{4, 5, 7, 9, 10, -1, 2}) << endl;
  cout << RotationCountOfRotatedArray::countRotations(vector<int>{1, 3, 8, 10}) << endl;
}
