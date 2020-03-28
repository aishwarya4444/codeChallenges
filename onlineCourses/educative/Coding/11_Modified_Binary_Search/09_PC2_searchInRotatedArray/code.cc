// https://www.educative.io/courses/grokking-the-coding-interview/N8XZQ1q1O46

#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/search-in-rotated-sorted-array/
// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

class SearchRotatedArray {
 public:
//  static int findIndex(const vector<int> &nums) {
//    int l=0, m, r=nums.size()-1;
//    while(l<r) {
//      m = l+(r-l)/2;
//      if(nums[m] < nums[r]) {
//        r = m;
//      } else if(nums[m] > nums[r]) {
//        l = m+1;
//      } else {
//        r--;
//      }
//    }
//    return l;
//  }
//
//  static int binarySearch(const vector<int> &a, int key, int l, int r) {
//    int m;
//    while(l<=r) {
//      m = l+(r-l)/2;
//      if(a[m]==key) {
//        return m;
//      }
//      if(key<a[m]) {
//        r = m-1;
//      } else {
//        l = m+1;
//      }
//    }
//    return -1;
//  }

  static int binarySearch(const vector<int> &a, int key, int l, int r) {
    int m;
    while(l<=r) {
      m = l+(r-l)/2;
      if(a[m] == key) {
        return m;
      }
      // the only difference from the previous solution,
      // if numbers at indexes start, mid, and end are same, we can't choose a side
      // the best we can do, is to skip one number from both ends as key != a[m]
      if(a[l]==a[m] && a[m]==a[r]) {
        l++;
        r--;
      } else if(a[l]<=a[m]) { // left side of array is sorted
        if(a[l]<=key && key<a[m]) {
          r = m-1;
        } else {
          l = m+1;
        }
      } else { // right side of array is sorted
        if(a[m]<key && key<=a[r]) {
          l = m+1;
        } else {
          r = m-1;
        }
      }
    }
    return -1;
  }

  static int search(const vector<int>& arr, int key) {
    // TODO: Write your code here
    int result, index = findIndex(arr);
    result = binarySearch(arr, key, 0, index-1);
    return result != -1 ? result : binarySearch(arr, key, index, arr.size()-1);
  }
};

int main(int argc, char* argv[]) {
  cout << SearchRotatedArray::search(vector<int>{10, 15, 1, 3, 8}, 15) << endl; // 1
  cout << SearchRotatedArray::search(vector<int>{4, 5, 7, 9, 10, -1, 2}, 10) << endl; // 4
  cout << SearchRotatedArray::search(vector<int>{1, 2, 3}, 3) << endl; // 2
  cout << SearchRotatedArray::search(vector<int>{1, 2, 3}, 1) << endl; // 0
  cout << SearchRotatedArray::search(vector<int>{1, 2, 3}, 2) << endl; // 1
  cout << SearchRotatedArray::search(vector<int>{3, 2, 1}, 1) << endl; // 2
  cout << SearchRotatedArray::search(vector<int>{4, 5, 6, 7, 0, 1, 2}, 0) << endl; // 4
  cout << SearchRotatedArray::search(vector<int>{4, 5, 6, 7, 0, 1, 2}, 3) << endl; // -1
}
