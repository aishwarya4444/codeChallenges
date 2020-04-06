// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5668515822436352

using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class ConnectRopes {
 public:
  static int minimumCostToConnectRopes(const vector<int> &ropeLengths) {
    int result = 0;
    // TODO: Write your code here
    priority_queue<int, vector<int>, greater<int> > minHeap;
    int l1, l2;
    for(auto length: ropeLengths) {
      minHeap.push(length);
    }
    while(minHeap.size()>1) {
      l1 = minHeap.top();
      minHeap.pop();
      l2 = minHeap.top();
      minHeap.pop();
      minHeap.push(l1+l2);
      result = result+l1+l2;
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  int result = ConnectRopes::minimumCostToConnectRopes(vector<int>{1, 3, 11, 5});
  cout << "Minimum cost to connect ropes: " << result << endl;
  result = ConnectRopes::minimumCostToConnectRopes(vector<int>{1, 3, 11, 5, 2});
  cout << "Minimum cost to connect ropes: " << result << endl;
}
