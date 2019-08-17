// https://www.educative.io/collection/page/5668639101419520/5671464854355968/6296665940033536

using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

// https://leetcode.com/problems/sliding-window-median/
// multiset solution is provided in leetcode .. have a look

template <class T, class Container = vector<T>,
          class Compare = less<typename Container::value_type> >
class priority_queue_remove : public priority_queue<T, Container, Compare> {
  public:
    void remove(const T &val) {
      auto loc = find(this->c.begin(), this->c.end(), val);
      if(loc == this->c.end()) {
        return;
      }
      this->c.erase(loc);
      make_heap(this->c.begin(), this->c.end(), this->comp);
    }
};

class SlidingWindowMedian {
  private:
    priority_queue_remove<int> maxHeap;
    priority_queue_remove<int, vector<int>, greater<int> > minHeap;

  public:
    void insert(int val) {
      maxHeap.push(val);
      minHeap.push(maxHeap.top());
      maxHeap.pop();
    }

    void rebalance() {
      if(maxHeap.size() < minHeap.size()) {
        maxHeap.push(minHeap.top());
        minHeap.pop();
      }
    }

    virtual vector<double> findSlidingWindowMedian(const vector<int> &nums, int k) {
      vector<double> result;
      // TODO: Write your code here
      int i;
      for(i=0; i<nums.size(); i++) {
        insert(nums[i]);
        rebalance();

        // find median and delete from heap if 'k' elements are captured
        if(i-k+1>=0) {
          // find median
          if(maxHeap.size()==minHeap.size()) {
            result.push_back(maxHeap.top()/2.0 + minHeap.top()/2.0);
          } else {
            result.push_back(maxHeap.top());
          }
          // delete the element which is not in window
          if(nums[i-k+1]<=maxHeap.top()) {
            maxHeap.remove(nums[i-k+1]);
          } else {
            minHeap.remove(nums[i-k+1]);
          }
          rebalance();
        }
      }
      return result;
    }
};

int main(int argc, char *argv[]) {
  SlidingWindowMedian slidingWindowMedian;
  vector<double> result =
      slidingWindowMedian.findSlidingWindowMedian(vector<int>{1, 2, -1, 3, 5}, 2);
  cout << "Sliding window medians are: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  slidingWindowMedian = SlidingWindowMedian();
  result = slidingWindowMedian.findSlidingWindowMedian(vector<int>{1, 2, -1, 3, 5}, 3);
  cout << "Sliding window medians are: ";
  for (auto num : result) {
    cout << num << " ";
  }
}
