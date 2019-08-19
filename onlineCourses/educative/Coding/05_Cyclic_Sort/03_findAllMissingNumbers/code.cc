// https://www.educative.io/collection/page/5668639101419520/5671464854355968/4893412715134976

using namespace std;

#include <iostream>
#include <vector>

// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

class AllMissingNumbers {
 public:
  static vector<int> findNumbers(vector<int> &nums) {
    vector<int> missingNumbers;
    // TODO: Write your code here
    int i=0, j;
    while(i<nums.size()) {
      j=nums[i]-1;
      if(nums[i]==nums[j]) {
        i++;
      } else {
        swap(nums[i], nums[j]);
      }
    }
    for(i=0; i<nums.size(); i++) {
      if(i+1!=nums[i]) {
        missingNumbers.push_back(i+1);
      }
    }
    return missingNumbers;
  }
};

int main(int argc, char *argv[]) {
  vector<int> v1 = {2, 3, 1, 8, 2, 3, 5, 1};
  vector<int> missing = AllMissingNumbers::findNumbers(v1);
  cout << "Missing numbers: ";
  for (auto num : missing) {
    cout << num << " ";
  }
  cout << endl;

  v1 = {2, 4, 1, 2};
  missing = AllMissingNumbers::findNumbers(v1);
  cout << "Missing numbers: ";
  for (auto num : missing) {
    cout << num << " ";
  }
  cout << endl;

  v1 = {2, 3, 2, 1};
  missing = AllMissingNumbers::findNumbers(v1);
  cout << "Missing numbers: ";
  for (auto num : missing) {
    cout << num << " ";
  }
  cout << endl;
}
