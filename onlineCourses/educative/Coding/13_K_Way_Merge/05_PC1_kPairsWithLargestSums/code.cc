// https://www.educative.io/collection/page/5668639101419520/5671464854355968/6588270395785216

using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class LargestPairs {
 public:
  struct sumCompare {
    bool operator()(const pair<int, int> &x, const pair<int, int> &y) {
      return x.first + x.second > y.first + y.second;
    }
  };

  static vector<pair<int, int>> findKLargestPairs(const vector<int> &nums1,
                                                  const vector<int> &nums2, int k) {
    priority_queue<pair<int,int>, vector<pair<int, int> >, sumCompare> minHeap;
    pair<int, int> minNode;
    vector<pair<int,int> > result;
    for (int i = 0; i < nums1.size() && i < k; i++) {
      for (int j = 0; j < nums2.size() && j < k; j++) {
        if (minHeap.size() < k) {
          minHeap.push(make_pair(nums1[i], nums2[j]));
        } else {
          minNode = minHeap.top();
          if(minNode.first+minNode.second > nums1[i]+nums2[j]) {
            break;
          } else {
            minHeap.push(make_pair(nums1[i],nums2[j]));
            minHeap.pop();
          }
        }
      }
    }
    while(minHeap.size() && k--) {
      result.push_back(minHeap.top());
      minHeap.pop();
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  auto result = LargestPairs::findKLargestPairs({9, 8, 2}, {6, 3, 1}, 3);
  cout << "Pairs with largest sum are: ";
  for (auto pair : result) {
    cout << "[" << pair.first << ", " << pair.second << "] ";
  }
}
