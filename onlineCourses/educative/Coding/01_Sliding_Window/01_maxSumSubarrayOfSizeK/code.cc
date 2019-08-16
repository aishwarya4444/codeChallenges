// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5177043027230720

using namespace std;

#include <iostream>
#include <vector>

class MaxSumSubArrayOfSizeK {
 public:
  static int findMaxSumSubArray(int k, const vector<int>& arr) {
    int maxSum = 0;
    // TODO: Write your code here
    int sum=0, n=0, N=arr.size();
    for(n; n<k; n++) {
      sum+=arr[n];
    }
    maxSum = sum;
    for(n; n<N; n++) {
      sum = sum - arr[n-k] + arr[n];
      maxSum = max(sum, maxSum);
    }
    return maxSum;
  }
};

int main(int argc, char* argv[]) {
  cout << "Maximum sum of a subarray of size K: "
       << MaxSumSubArrayOfSizeK::findMaxSumSubArray(3, vector<int>{2, 1, 5, 1, 3, 2}) << endl;
  cout << "Maximum sum of a subarray of size K: "
       << MaxSumSubArrayOfSizeK::findMaxSumSubArray(2, vector<int>{2, 3, 4, 1, 5}) << endl;
}
