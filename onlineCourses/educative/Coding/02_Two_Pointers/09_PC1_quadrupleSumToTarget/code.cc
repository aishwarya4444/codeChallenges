// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5796496094003200

using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class QuadrupleSumToTarget {
 public:
  static vector<vector<int>> searchQuadruplets(vector<int> &arr, int target) {
    vector<vector<int>> quadruplets;
    // TODO: Write your code here
    vector<int> res;
    int i, j, l, r, sum, N=arr.size();
    sort(arr.begin(), arr.end());
    for(i=0; i<N-3; i++) {
      if(i>0 && arr[i]==arr[i-1]) {
        continue;
      }
      for(j=i+1; j<N-2; j++) {
        if(j>i+1 && arr[j]==arr[j-1]) {
          continue;
        }
        l=j+1;
        r=N-1;
        while(l<r) {
          if(l>j+1 && arr[l]==arr[l-1]) {
            l++;
            continue;
          }
          if(r<N-1 && arr[r]==arr[r+1]) {
            r--;
            continue;
          }
          sum = arr[i]+arr[j]+arr[l]+arr[r];
          if(sum==target) {
            res.clear();
            res.push_back(arr[i]);
            res.push_back(arr[j]);
            res.push_back(arr[l]);
            res.push_back(arr[r]);
            quadruplets.push_back(res);
            l++;
            r--;
          } else if(sum<target) {
            l++;
          } else {
            r--;
          }
        }
      }
    }
    return quadruplets;
  }
};

int main(int argc, char *argv[]) {
  vector<int> vec = {4, 1, 2, -1, 1, -3};
  auto result = QuadrupleSumToTarget::searchQuadruplets(vec, 1);
  for (auto vec : result) {
    cout << "[";
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << "]";
  }
  cout << endl;

  vec = {2, 0, -1, 1, -2, 2};
  result = QuadrupleSumToTarget::searchQuadruplets(vec, 2);
  for (auto vec : result) {
    cout << "[";
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << "]";
  }
}
