// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5902703286812672
// https://leetcode.com/problems/subarray-product-less-than-k/description/
// [1] sliding window solution - O(n)
// [2] look at binary solution also

using namespace std;

#include <deque>
#include <iostream>
#include <vector>

/*
// Sliding Window
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int count=0, prod=1, l=0, r, N=nums.size();
        for(r=0; r<N; r++) {
            prod*=nums[r];
            while(prod>=k) {
                prod /= nums[l];
                l++;
            }
            count = count+r-l+1;
        }
        return count;
    }
};
*/
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
