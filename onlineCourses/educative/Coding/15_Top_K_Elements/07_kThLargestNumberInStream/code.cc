// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5708235679989760

using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class KthLargestNumberInStream {
  public:
    priority_queue<int, vector<int>, greater<int> > minHeap;
    int K;
    KthLargestNumberInStream(const vector<int> &nums, int k) {
    // TODO: Write your code here
      K=k;
      for(auto num: nums) {
        add(num);
      }
    }

    virtual int add(int num) {
      // TODO: Write your code here
      if(minHeap.size()<K) {
        minHeap.push(num);
      } else if(num>minHeap.top()) {
        minHeap.push(num);
        minHeap.pop();
      }
      return minHeap.top();
    }
};

int main(int argc, char *argv[]) {
  KthLargestNumberInStream kthLargestNumber({3, 1, 5, 12, 2, 11}, 4);
  cout << "4th largest number is: " << kthLargestNumber.add(6) << endl;
  cout << "4th largest number is: " << kthLargestNumber.add(13) << endl;
  cout << "4th largest number is: " << kthLargestNumber.add(4) << endl;
}
