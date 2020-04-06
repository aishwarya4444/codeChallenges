// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5728885882748928

using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class KLargestNumbers {
 public:
  static vector<int> findKLargestNumbers(const vector<int>& nums, int k) {
    vector<int> result;
    // TODO: Write your code here
    priority_queue<int, vector<int>, greater<int> > minHeap;
    int n, N=nums.size();
    for(n=0; n<N; n++) {
      if(n<k) minHeap.push(nums[n]);
      else if(minHeap.top()<nums[n]) {
        minHeap.pop();
        minHeap.push(nums[n]);
      }
    }
    while(k--) {
      result.push_back(minHeap.top());
      minHeap.pop();
    }
    return result;
  }
};

int main(int argc, char* argv[]) {
  vector<int> result = KLargestNumbers::findKLargestNumbers(vector<int>{3, 1, 5, 12, 2, 11}, 3);
  cout << "Here are the top K numbers: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = KLargestNumbers::findKLargestNumbers(vector<int>{5, 12, 11, -1, 12}, 3);
  cout << "Here are the top K numbers: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}
