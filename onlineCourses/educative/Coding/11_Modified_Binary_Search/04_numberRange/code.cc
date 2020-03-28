// https://www.educative.io/courses/grokking-the-coding-interview/R1B78K9oBEz

using namespace std;

#include <iostream>
#include <vector>

// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class FindRange {
 public:
  static pair<int, int> findRange(const vector<int> &arr, int key) {
    pair<int, int> result(-1, -1);
    // TODO: Write your code here
    int l=-1, r=-1, lb, ub, mid;
    // find start of range 'l'
    lb=0;
    ub=arr.size()-1;
    while(lb<=ub) {
      mid=lb+(ub-lb)/2;
      if(arr[mid]==key) {
        l=mid;
        ub=mid-1;
      } else if(key<arr[mid]) {
        ub=mid-1;
      } else {
        lb=mid+1;
      }
    }
    // find end of range 'r'
    lb=0;
    ub=arr.size()-1;
    while(lb<=ub) {
      mid=lb+(ub-lb)/2;
      if(arr[mid]==key) {
        r=mid;
        lb=mid+1;
      } else if(key<arr[mid]) {
        ub=mid-1;
      } else {
        lb=mid+1;
      }
    }
    if(l!=-1 && r!=-1) {
      return make_pair(l, r);
    }
    return result;
  }
};

/*
class Solution {
    int lowerBound(vector<int> &nums, int target) {
        int start = 0, last = nums.size()-1;
        while(start != last) {
            int mid = (start+last) >> 1;
            if(nums[mid] >= target) {
                last = mid;
            }
            else {
                start = mid+1;
            }
        }
        if(nums[start] != target)
            return -1;
        return start;
    }

    int upperBound(vector<int> &nums, int target) {
        int start = 0, last = nums.size()-1;
        while(start != last) {
            int mid = (start + last + 1) >> 1;
            if(nums[mid] > target) {
                last = mid-1;
            }
            else {
                start = mid;
            }
        }
        if(nums[start] != target)
            return -1;
        return start;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) {
            return vector<int> {-1,-1};
        }
        int lb = lowerBound(nums, target);
        int ub = upperBound(nums, target);
        return vector<int> {lb, ub};
    }
};
*/

int main(int argc, char *argv[]) {
  pair<int, int> result = FindRange::findRange(vector<int>{4, 6, 6, 6, 9}, 6);
  cout << "Range: [" << result.first << ", " << result.second << "]" << endl;
  result = FindRange::findRange(vector<int>{1, 3, 8, 10, 15}, 10);
  cout << "Range: [" << result.first << ", " << result.second << "]" << endl;
  result = FindRange::findRange(vector<int>{1, 3, 8, 10, 15}, 12);
  cout << "Range: [" << result.first << ", " << result.second << "]" << endl;
}
