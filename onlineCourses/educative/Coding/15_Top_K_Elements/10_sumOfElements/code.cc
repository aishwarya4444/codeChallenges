// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5648269346603008

using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class SumOfElements {
 public:
  static int findSumOfElements(const vector<int> &nums, int k1, int k2) {
    int elementSum = 0;
    // TODO: Write your code here
    priority_queue<int, vector<int>, greater<int> > minHeap;
    int n, N=nums.size();
    for(n=0; n<N; n++) {
      minHeap.push(nums[n]);
    }
    for(n=0; n<k1; n++) {
      minHeap.pop();
    }
    for(n=k1; n<k2-1; n++) {
      elementSum += minHeap.top();
      minHeap.pop();
    }
    return elementSum;
  }
};

int main(int argc, char *argv[]) {
  int result = SumOfElements::findSumOfElements(vector<int>{1, 3, 12, 5, 15, 11}, 3, 6);
  cout << "Sum of all numbers between k1 and k2 smallest numbers: " << result << endl;

  result = SumOfElements::findSumOfElements(vector<int>{3, 5, 8, 7}, 1, 4);
  cout << "Sum of all numbers between k1 and k2 smallest numbers: " << result << endl;
}
