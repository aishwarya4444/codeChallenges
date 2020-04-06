// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5696381570252800

using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class KthSmallestNumber {
 public:
  static int findKthSmallestNumber(const vector<int> &nums, int k) {
    // TODO: Write your code here
    priority_queue<int> maxHeap;
    int n, N=nums.size();
    for(n=0; n<N; n++) {
      if(n<k) maxHeap.push(nums[n]);
      else if(nums[n]<maxHeap.top()) {
        maxHeap.pop();
        maxHeap.push(nums[n]);
      }
    }
    return maxHeap.size() ? maxHeap.top() : -1;
  }
};

int main(int argc, char *argv[]) {
  int result = KthSmallestNumber::findKthSmallestNumber(vector<int>{1, 5, 12, 2, 11, 5}, 3);
  cout << "Kth smallest number is: " << result << endl;

  // since there are two 5s in the input array, our 3rd and 4th smallest numbers should be a '5'
  result = KthSmallestNumber::findKthSmallestNumber(vector<int>{1, 5, 12, 2, 11, 5}, 4);
  cout << "Kth smallest number is: " << result << endl;

  result = KthSmallestNumber::findKthSmallestNumber(vector<int>{5, 12, 11, -1, 12}, 3);
  cout << "Kth smallest number is: " << result << endl;
}
