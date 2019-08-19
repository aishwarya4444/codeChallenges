// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5115834240335872

using namespace std;

#include <iostream>
#include <vector>

// https://leetcode.com/problems/find-all-duplicates-in-an-array/

class FindAllDuplicate {
 public:
  static vector<int> findNumbers(vector<int> &nums) {
    vector<int> duplicateNumbers;
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
        duplicateNumbers.push_back(nums[i]);
      }
    }
    return duplicateNumbers;
  }
};

int main(int argc, char *argv[]) {
  vector<int> v1 = {3, 4, 4, 5, 5};
  vector<int> duplicates = FindAllDuplicate::findNumbers(v1);
  cout << "Duplicates are: ";
  for (auto num : duplicates) {
    cout << num << " ";
  }
  cout << endl;

  v1 = {5, 4, 7, 2, 3, 5, 3};
  duplicates = FindAllDuplicate::findNumbers(v1);
  cout << "Duplicates are: ";
  for (auto num : duplicates) {
    cout << num << " ";
  }
  cout << endl;
}
