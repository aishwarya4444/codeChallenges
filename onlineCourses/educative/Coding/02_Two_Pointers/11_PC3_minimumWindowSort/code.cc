// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5312042204397568

using namespace std;

#include <iostream>
#include <limits>
#include <vector>
#include <climits>

// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

class ShortestWindowSort {
 public:
  static int sort(const vector<int>& arr) {
    // TODO: Write your code here
    int N=arr.size(), l=0, m, r=N-1, minElem = INT_MAX, maxElem = INT_MIN;
    // index where left half of sorted array ends
    while(l<N-1 && arr[l]<=arr[l+1]) {
      l++;
    }
    // if we reach last index, array is sorted
    if(l==N-1) {
      return 0;
    }
    // index where right half of sorted array starts
    while(r>0 && arr[r-1]<=arr[r]) {
      r--;
    }
    // find max and min value in unsorted part of array
    for(m=l; m<=r; m++) {
      minElem = min(arr[m], minElem);
      maxElem = max(arr[m], maxElem);
    }
    // move back in left array to find index where min element should be present
    while(l>0 && minElem<arr[l-1]) {
      l--;
    }
    // move ahead in right array to find index where max element should be present
    while(r<N-1 && maxElem>arr[r+1]) {
      r++;
    }
    return (r-l+1);
  }
};

int main(int argc, char* argv[]) {
  cout << ShortestWindowSort::sort(vector<int>{1, 2, 5, 3, 7, 10, 9, 12}) << endl;
  cout << ShortestWindowSort::sort(vector<int>{1, 3, 2, 0, -1, 7, 10}) << endl;
  cout << ShortestWindowSort::sort(vector<int>{1, 2, 3}) << endl;
  cout << ShortestWindowSort::sort(vector<int>{3, 2, 1}) << endl;
}
