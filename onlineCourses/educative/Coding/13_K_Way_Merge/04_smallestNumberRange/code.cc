// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5553519291531264

using namespace std;

#include <iostream>
#include <limits>
#include <queue>
#include <vector>

// https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/

class SmallestRange {
 public:
  struct compare {
    bool operator()(const pair<int, pair<int,int>> &p1, const pair<int, pair<int,int>> &p2) {
      return p1.first > p2.first;
    }
  };

  static pair<int, int> findSmallestRange(const vector<vector<int>> &lists) {
    int maxElement=lists[0][0], row, col, n, N=lists.size();
    pair<int, int> range;
    pair<int, pair<int, int>> minNode;
    priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, compare> minHeap;
    for(n=0; n<N; n++) {
      minHeap.push(make_pair(lists[n][0], make_pair(n,0)));
      maxElement = max(maxElement, lists[n][0]);
    }
    range = make_pair(minHeap.top().first, maxElement);
    while(minHeap.size() == lists.size()) {
      minNode = minHeap.top();
      minHeap.pop();
      row = minNode.second.first;
      col = minNode.second.second;
      if(range.second - range.first > maxElement - minNode.first) {
        range.first = minNode.first;
        range.second = maxElement;
      }
      if(col < lists[row].size()-1) {
        minHeap.push(make_pair(lists[row][col+1], make_pair(row, col+1)));
        maxElement = max(maxElement, lists[row][col+1]);
      }
    }
    return range;
  }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> lists = {{1, 5, 8}, {4, 12}, {7, 8, 10}};
  auto result = SmallestRange::findSmallestRange(lists);
  cout << "Smallest range is: [" << result.first << ", " << result.second << "]";
}
