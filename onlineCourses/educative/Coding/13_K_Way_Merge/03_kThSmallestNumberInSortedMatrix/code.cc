// https://www.educative.io/collection/page/5668639101419520/5671464854355968/4605334997958656

using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class KthSmallestInSortedMatrix {
  public:
    struct compareGreater {
      bool operator()(pair<int, pair<int,int> > &p1, pair<int, pair<int,int> > &p2) {
        return p1.first > p2.first;
      }
    };
    static int findKthSmallest(const vector<vector<int>> &matrix, int k) {
      int result = -1;
      // TODO: Write your code here
      int i, index, count=0;
      pair<int, pair<int,int> > tempNode;
      priority_queue<pair<int, pair<int,int> >, vector<pair<int, pair<int,int> > >, compareGreater> minHeap;
      for(i=0; i<matrix.size(); i++) {
        minHeap.push(make_pair(matrix[i][0], make_pair(i, 0)));
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
        if(index+1 != matrix[i].size()) {
          minHeap.push(make_pair(matrix[i][index+1], make_pair(i, index+1)));
        }
      }
      return result;
    }
};

int main(int argc, char *argv[]) {
  vector<vector<int>> matrix2 = {vector<int>{2, 6, 8}, vector<int>{3, 7, 10},
                                 vector<int>{5, 8, 11}};
  int result = KthSmallestInSortedMatrix::findKthSmallest(matrix2, 5);
  cout << "Kth smallest number is: " << result << endl;
}
