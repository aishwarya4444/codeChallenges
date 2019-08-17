// https://www.educative.io/collection/page/5668639101419520/5671464854355968/6308926461050880

using namespace std;

#include <iostream>
#include <queue>
#include <vector>

// https://leetcode.com/problems/find-median-from-data-stream/

class MedianOfAStream {
  public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
  virtual void insertNum(int num) {
    // TODO: Write your code here
    maxHeap.push(num);
    minHeap.push(maxHeap.top());
    maxHeap.pop();

    // rebalance
    if(maxHeap.size() < minHeap.size()) {
      maxHeap.push(minHeap.top());
      minHeap.pop();
    }
  }

  virtual double findMedian() {
    // TODO: Write your code here
    if(maxHeap.size()==minHeap.size()) {
      return (maxHeap.top()+minHeap.top())/2.0;
    }
    return maxHeap.top();
  }
};

int main(int argc, char *argv[]) {
  MedianOfAStream medianOfAStream;
  medianOfAStream.insertNum(3);
  medianOfAStream.insertNum(1);
  cout << "The median is: " << medianOfAStream.findMedian() << endl;
  medianOfAStream.insertNum(5);
  cout << "The median is: " << medianOfAStream.findMedian() << endl;
  medianOfAStream.insertNum(4);
  cout << "The median is: " << medianOfAStream.findMedian() << endl;
}
