// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5554621957275648
// https://leetcode.ca/2016-08-15-259-3Sum-Smaller/

using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class TripletWithSmallerSum {
 public:
  static int searchTriplets(vector<int> &arr, int target) {
    int count = -1;
    // TODO: Write your code here
    int i, l, r, sum, N=arr.size();
    count = 0;
    sort(arr.begin(), arr.end());
    for(i=0; i<N-2; i++) {
      l = i+1;
      r = N-1;
      while(l<r) {
        sum = arr[i]+arr[l]+arr[r];
        if(sum < target) {
          count = count+r-l;
          l++;
        } else {
          r--;
        }
      }
    }
    return count;
  }
};

int main(int argc, char *argv[]) {
  vector<int> vec = {-1, 0, 2, 3};
  cout << TripletWithSmallerSum::searchTriplets(vec, 3) << endl;
  vec = {-1, 4, 2, 1, 3};
  cout << TripletWithSmallerSum::searchTriplets(vec, 5) << endl;
}
