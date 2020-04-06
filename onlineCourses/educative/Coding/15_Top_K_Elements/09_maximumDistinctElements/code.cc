// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5741384237580288

using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class MaximumDistinctElements {
  public:
    struct compareGreater {
      // bool opertaor()(const pair<int, int> &p1, const pair<int,int> &p2) {
      //   return p1.second > p2.second;
      // }
      bool operator()(const pair<int, int> &x, const pair<int, int> &y) {
        return x.second > y.second;
      }
    };

    static int findMaximumDistinctElements(const vector<int> &nums, int k) {
      int distinctElementsCount = 0;
      // TODO: Write your code here
      int freq;
      unordered_map<int, int> m;
      priority_queue<pair<int, int>, vector<pair<int, int> >, compareGreater > minHeap;
      for(auto num: nums) {
        m[num]++;
      }
      for(auto entry: m) {
        if(entry.second==1) {
          distinctElementsCount++;
        } else {
          minHeap.push(entry);
        }
      }
      while(k>0 && minHeap.size()) {
        freq = minHeap.top().second;
        k = k - (freq-1);
        if(k>=0) {
          distinctElementsCount++;
        }
        minHeap.pop();
      }
      if(k>0) {
        distinctElementsCount -= k;
      }
      return distinctElementsCount;
    }
};

int main(int argc, char *argv[]) {
  int result =
      MaximumDistinctElements::findMaximumDistinctElements(vector<int>{7, 3, 5, 8, 5, 3, 3}, 2);
  cout << "Maximum distinct numbers after removing K numbers: " << result << endl;

  result = MaximumDistinctElements::findMaximumDistinctElements(vector<int>{3, 5, 12, 11, 12}, 3);
  cout << "Maximum distinct numbers after removing K numbers: " << result << endl;

  result = MaximumDistinctElements::findMaximumDistinctElements(
      vector<int>{1, 2, 3, 3, 3, 3, 4, 4, 5, 5, 5}, 2);
  cout << "Maximum distinct numbers after removing K numbers: " << result << endl;
}
