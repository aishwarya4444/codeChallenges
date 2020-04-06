// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5761493274460160

using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class TopKFrequentNumbers {
  struct valueCompare {
    char operator()(const pair<int, int> &x, const pair<int, int> &y) {
      return x.second > y.second;
    }
  };

 public:
  static vector<int> findTopKFrequentNumbers(const vector<int> &nums, int k) {
    vector<int> topNumbers;
    // TODO: Write your code here
    unordered_map<int, int> m;
    priority_queue<pair<int,int>, vector<pair<int, int> >, valueCompare > minHeap;
    int n=0, N=nums.size();
    for(n=0; n<N; n++) {
      m[nums[n]]++;
    }
    for(auto entry: m) {
      minHeap.push(entry);
      if(minHeap.size() > k) {
        minHeap.pop();
      }
    }
    while(minHeap.size()) {
      topNumbers.push_back(minHeap.top().first);
      minHeap.pop();
    }
    return topNumbers;
  }
};

int main(int argc, char *argv[]) {
  vector<int> result =
      TopKFrequentNumbers::findTopKFrequentNumbers(vector<int>{1, 3, 5, 12, 11, 12, 11}, 2);
  cout << "Here are the K frequent numbers: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = TopKFrequentNumbers::findTopKFrequentNumbers(vector<int>{5, 12, 11, 3, 11}, 2);
  cout << "Here are the K frequent numbers: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}
