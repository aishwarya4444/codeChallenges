// https://www.educative.io/collection/page/5668639101419520/5671464854355968/4578892830474240

using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class MinSizeSubArraySum {
 public:
  static int findMinSubArray(int S, const vector<int>& arr) {
    // TODO: Write your code here
    // int k, n, N=arr.size(), sum, size=N+1;
    // for(k=1; k<=N; k++) {
    //   sum=0;
    //   for(n=0; n<k; n++) {
    //     sum+=arr[n];
    //   }
    //   if(sum>=S) {
    //     size = min(size, k);
    //   }
    //   for(n; n<N; n++) {
    //     sum = sum - arr[n-k] + arr[n];
    //     if(sum>=S) {
    //       size = min(size, k);
    //     }
    //   }
    // }
    // return size==N+1 ? -1 : size;
    int sum=0, start=0, end=0, N=arr.size(), size=N+1;
    while(end<N) {
      sum += arr[end];
      while(sum>=S) {
        size = min(size, end-start+1);
        sum -= arr[start];
        start++;
      }
      end++;
    }
    return size==N+1 ? -1 : size;
  }
};

int main(int argc, char* argv[]) {
  int result = MinSizeSubArraySum::findMinSubArray(7, vector<int>{2, 1, 5, 2, 3, 2});
  cout << "Smallest subarray length: " << result << endl;
  result = MinSizeSubArraySum::findMinSubArray(7, vector<int>{2, 1, 5, 2, 8});
  cout << "Smallest subarray length: " << result << endl;
  result = MinSizeSubArraySum::findMinSubArray(8, vector<int>{3, 4, 1, 1, 6});
  cout << "Smallest subarray length: " << result << endl;
}
