// https://www.educative.io/collection/page/5668639101419520/5671464854355968/6210874538721280

using namespace std;

#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

// https://leetcode.com/problems/3sum-closest/

class TripletSumCloseToTarget {
 public:
  static int searchTriplet(vector<int>& arr, int targetSum) {
    // TODO: Write your code here
    int i, l, r, N=arr.size(), sum=0;
    int prevSum = arr[0]+arr[1]+arr[2];
    sort(arr.begin(), arr.end());
    for(i=0; i<N-2; i++) {
      l=i+1;
      r=N-1;
      while(l<r) {
        sum = arr[i]+arr[l]+arr[r];
        if(abs(targetSum-prevSum) >= abs(targetSum-sum)) {
          prevSum = sum;
        }
        if(targetSum == sum) {
          break;
        }
        if(sum > targetSum) {
          l++;
        } else {
          r--;
        }
      }
    }
    return prevSum;
  }
};

int main(int argc, char* argv[]) {
  vector<int> vec = {-2, 0, 1, 2};
  cout << TripletSumCloseToTarget::searchTriplet(vec, 2) << endl;
  vec = {-3, -1, 1, 2};
  cout << TripletSumCloseToTarget::searchTriplet(vec, 1) << endl;
  vec = {1, 0, 1, 1};
  cout << TripletSumCloseToTarget::searchTriplet(vec, 100) << endl;
}
