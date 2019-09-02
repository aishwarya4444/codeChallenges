// https://www.educative.io/courses/grokking-the-coding-interview/RMyRR6wZoYK

using namespace std;

#include <iostream>
#include <vector>

// https://leetcode.com/problems/peak-index-in-a-mountain-array/
// https://leetcode.com/problems/find-peak-element/
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

class MaxInBitonicArray {
 public:
  static int findMax(const vector<int>& arr) {
    // TODO: Write your code here
    int l=0, m, r=arr.size()-1;
    while(l<r) {
      m = l+(r-l)/2;
      if(arr[m]>arr[m+1]) {
        r = m;
      } else {
        l = m+1;
      }
    }
    return arr[l];
  }

};

int main(int argc, char* argv[]) {
  cout << MaxInBitonicArray::findMax(vector<int>{1, 3, 8, 12, 4, 2}) << endl;
  cout << MaxInBitonicArray::findMax(vector<int>{3, 8, 3, 1}) << endl;
  cout << MaxInBitonicArray::findMax(vector<int>{1, 3, 8, 12}) << endl;
  cout << MaxInBitonicArray::findMax(vector<int>{10, 9, 8}) << endl;
}
