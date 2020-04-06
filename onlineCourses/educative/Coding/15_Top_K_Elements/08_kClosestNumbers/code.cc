// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5474975244877824

using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class KClosestElements {
  private:
    static int binarySearchClosest(const vector<int> &arr, int target) {
      int lb=0, mid, ub=arr.size()-1;
      while(lb<=ub) {
        mid = lb + (ub-lb)/2;
        if(arr[mid]==target) return mid;
        if(target<arr[mid]) ub = mid-1;
        else lb = mid+1;
      }
      return lb;
    }

  public:
    struct numCompare {
      bool operator()(const pair<int, int> &x, const pair<int, int> &y) { return x.first > y.first; }
    };

    static vector<int> findClosestElements(const vector<int> &arr, int K, int X) {
      vector<int> result;
      // TODO: Write your code here
      // we could have used a maxHeap of size K
      // but comparator given was for minHeap
      // so our heap size in this case is 2K
      priority_queue<pair<int, int>, vector<pair<int, int> >, numCompare> minHeap;
      int i, num, closestIndex = binarySearchClosest(arr, X);
      for(i=closestIndex-K; i<=closestIndex+K; i++) {
        num = arr[i];
        minHeap.push(make_pair(abs(X-num), num));
      }
      while(K--) {
        result.push_back(minHeap.top().second);
        minHeap.pop();
      }
      return result;
    }
};

int main(int argc, char *argv[]) {
  vector<int> result = KClosestElements::findClosestElements(vector<int>{5, 6, 7, 8, 9}, 3, 7);
  cout << "'K' closest numbers to 'X' are: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = KClosestElements::findClosestElements(vector<int>{2, 4, 5, 6, 9}, 3, 6);
  cout << "'K' closest numbers to 'X' are: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}
