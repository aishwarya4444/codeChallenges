// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5670249378611200

using namespace std;

#include <iostream>
#include <vector>

class Subsets {
 public:
  static vector<vector<int>> findSubsets(const vector<int>& nums) {
    vector<vector<int>> subsets;
    // TODO: Write your code here
    vector<int> subset;
    int i, N;
    subsets.push_back(subset);
    for(auto num: nums) {
      N=subsets.size();
      for(i=0; i<N; i++) {
        subset = subsets[i];
        subset.push_back(num);
        subsets.push_back(subset);
      }
    }
    return subsets;
  }
};

int main(int argc, char* argv[]) {
  vector<vector<int>> result = Subsets::findSubsets(vector<int>{1, 3});
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }

  result = Subsets::findSubsets(vector<int>{1, 5, 3});
  cout << "Here is the list of subsets: " << endl;
  for (auto vec : result) {
    for (auto num : vec) {
      cout << num << " ";
    }
    cout << endl;
  }
}
