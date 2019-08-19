// https://www.educative.io/collection/page/5668639101419520/5671464854355968/4890648534581248

using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class KthSmallestInMSortedArrays {
  public:
    struct compareGreater {
      bool operator()(pair<int, pair<int,int> > &p1, pair<int, pair<int,int> > &p2) {
        return p1.first > p2.first;
      }
    };
    static int findKthSmallest(const vector<vector<int>> &lists, int k) {
      int result = -1;
      // TODO: Write your code here
      int i, index, count=0;
      pair<int, pair<int,int> > tempNode;
      priority_queue<pair<int, pair<int,int> >, vector<pair<int, pair<int,int> > >, compareGreater> minHeap;
      for(i=0; i<lists.size(); i++) {
        minHeap.push(make_pair(lists[i][0], make_pair(i, 0)));
      }
      while(minHeap.size()) {
        tempNode = minHeap.top();
        minHeap.pop();
        count++;
        if(count == k) {
          result = tempNode.first;
          break;
        }
        i = tempNode.second.first;
        index = tempNode.second.second;
        if(index+1 != lists[i].size()) {
          minHeap.push(make_pair(lists[i][index+1], make_pair(i, index+1)));
        }
      }
      return result;
    }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> lists = {{2, 6, 8}, {3, 6, 7}, {1, 3, 4}};
  int result = KthSmallestInMSortedArrays::findKthSmallest(lists, 5);
  cout << "Kth smallest number is: " << result;
}
