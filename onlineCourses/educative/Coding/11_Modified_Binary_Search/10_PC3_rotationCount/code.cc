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
      if(l<m && nums[m-1]>nums[m]) {
        return m;
      } else if(m<r && nums[m]>nums[m+1]) {
        return m+1;
      }

      // check for duplicates is same as
      // "search in rotated array"
      // just one more addition .. skip numbers if they are not smallest
      if(nums[l]==nums[m] && nums[m]==nums[r]) {
        if(nums[l]>nums[l+1]) {
          return l+1;
        }
        l++;
        if(nums[r-1]>nums[r]) {
          return r;
        }
        r--;
      }

      if(nums[l] < nums[m] || (nums[l]==nums[m] && nums[m]>nums[r])) { // left is sorted
        l = m+1;
      } else { // right is sorted
        r = m-1;
      }
    }
    return 0; // array is not rotated
  }
};

/*
// https://www.youtube.com/watch?v=aCb1zKMimDQ

class Solution {
public:
    int countRotations(vector<int>& nums) {
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
*/

int main(int argc, char* argv[]) {
  cout << RotationCountOfRotatedArray::countRotations(vector<int>{10, 15, 1, 3, 8}) << endl;
  cout << RotationCountOfRotatedArray::countRotations(vector<int>{4, 5, 7, 9, 10, -1, 2}) << endl;
  cout << RotationCountOfRotatedArray::countRotations(vector<int>{1, 3, 8, 10}) << endl;
}
