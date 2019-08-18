// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5654100301578240

using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>

class SubsetWithDuplicates {
 public:
  static vector<vector<int>> findSubsets(vector<int>& nums) {
    vector<vector<int>> subsets;
    // TODO: Write your code here
    vector<int> subset;
    int n, num, i, start=0, end=0;
    sort(nums.begin(), nums.end());
    subsets.push_back(subset);
    for(n=0; n<nums.size(); n++) {
      num = nums[n];
      if(n>0 && num==nums[n-1]) {
        start = end;
      } else {
        start = 0;
      }
      end = subsets.size();
      for(i=start; i<end; i++) {
        subset = subsets[i];
        subset.push_back(num);
        subsets.push_back(subset);
      }
    }
    return subsets;
  }
};

int main(int argc, char* argv[]) {
  vector<int> vec = {1, 3, 3};
  vector<vector<int>> result = SubsetWithDuplicates::findSubsets(vec);
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }

  vec = {1, 5, 3, 3};
  result = SubsetWithDuplicates::findSubsets(vec);
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}
