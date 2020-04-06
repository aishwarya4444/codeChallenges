// https://www.educative.io/collection/page/5668639101419520/5671464854355968/6528376640634880

using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class Point {
 public:
  int x = 0;
  int y = 0;

  Point(int x, int y) {
    this->x = x;
    this->y = y;
  }

  int distFromOrigin() const {
    // ignoring sqrt
    return (x * x) + (y * y);
  }
};

class KClosestPointsToOrigin {
  public:
    struct valueCompareLess {
      char operator()(const Point &x, const Point &y) {
        return x.distFromOrigin() < y.distFromOrigin();
      }
    };

    static vector<Point> findClosestPoints(const vector<Point>& points, int k) {
      vector<Point> result;
      // TODO: Write your code here
      priority_queue<Point, vector<Point>, valueCompareLess> maxHeap;
      int n=0, N=points.size();
      for(; n<k; n++) {
        maxHeap.push(points[n]);
      }
      for(; n<N; n++) {
        if(points[n].distFromOrigin()<maxHeap.top().distFromOrigin()) {
          maxHeap.push(points[n]);
          maxHeap.pop();
        }
      }
      while(maxHeap.size()) {
        result.push_back(maxHeap.top());
        maxHeap.pop();
      }
      return result;
    }
};

int main(int argc, char* argv[]) {
  vector<Point> maxHeap = KClosestPointsToOrigin::findClosestPoints({{1, 3}, {3, 4}, {2, -1}}, 2);
  cout << "Here are the k points closest the origin: ";
  for (auto p : maxHeap) {
    cout << "[" << p.x << " , " << p.y << "] ";
  }
}
