// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5144878352695296

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

class FirstKMissingPositive {
 public:
  static vector<int> findNumbers(vector<int> &nums, int k) {
    vector<int> missingNumbers;
    // TODO: Write your code here
    unordered_set<int> extra;
    int i=0, j;
    while(i<nums.size()) {
      j = nums[i]-1;
      if(j>=0 && j<nums.size() && nums[i]!=nums[j]) {
        swap(nums[i], nums[j]);
      } else {
        i++;
      }
    }
    for(i=0; i<nums.size() && missingNumbers.size()<k; i++) {
      if(i+1!=nums[i]) {
        missingNumbers.push_back(i+1);
        extra.insert(nums[i]);
      }
    }
    for(i=1; missingNumbers.size()<k; i++) {
        j = i+nums.size();
        if(extra.find(j) == extra.end()) {
            missingNumbers.push_back(j);
        }
    }
    return missingNumbers;
  }
};

int main(int argc, char *argv[]) {
  vector<int> v1 = {3, -1, 4, 5, 5};
  vector<int> missingNumbers = FirstKMissingPositive::findNumbers(v1, 3);
  cout << "Missing numbers: ";
  for (auto num : missingNumbers) {
    cout << num << " ";
  }
  cout << endl;

  v1 = {2, 3, 4};
  missingNumbers = FirstKMissingPositive::findNumbers(v1, 3);
  cout << "Missing numbers: ";
  for (auto num : missingNumbers) {
    cout << num << " ";
  }
  cout << endl;

  v1 = {-2, -3, 4};
  missingNumbers = FirstKMissingPositive::findNumbers(v1, 2);
  cout << "Missing numbers: ";
  for (auto num : missingNumbers) {
    cout << num << " ";
  }
  cout << endl;
}
