// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5902703286812672

using namespace std;

#include <deque>
#include <iostream>
#include <vector>

class SubarrayProductLessThanK {
 public:
  static vector<vector<int>> findSubarrays(const vector<int>& arr, int target) {
    vector<vector<int>> result;
    // TODO: Write your code here
    int prod, i, j, N=arr.size();
    vector<int> res;
    for(i=0; i<N; i++) {
      prod=1;
      res.clear();
      for(j=i; j<N; j++) {
        res.push_back(arr[j]);
        prod *= arr[j];
        if(prod<target) {
          result.push_back(res);
        } else {
          break;
        }
      }
    }
    return result;
  }
};

int main(int argc, char* argv[]) {
  auto result = SubarrayProductLessThanK::findSubarrays(vector<int>{2, 5, 3, 10}, 30);
  for (auto vec : result) {
    cout << "[";
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << "]";
  }
  cout << endl;

  result = SubarrayProductLessThanK::findSubarrays(vector<int>{8, 2, 6, 5}, 50);
  for (auto vec : result) {
    cout << "[";
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << "]";
  }
}
