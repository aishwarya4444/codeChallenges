// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5753318183796736

using namespace std;

#include <iostream>
#include <vector>

// https://leetcode.com/problems/first-missing-positive/

class FirstMissingPositive {
 public:
  static int findNumber(vector<int> &nums) {
    // TODO: Write your code here
    int i=0, j;
    while(i<nums.size()) {
      // integer overflow case .. if value equals INT_MIN then don't subtract 1
      j = nums[i]==INT_MIN ? nums[i] : nums[i]-1;
      // or use
      // j = nums[i]<0 ? nums[i] : nums[i]-1;
      if(nums[j]>=0 && nums[j]<nums.size() && nums[i]!=nums[j]) {
        swap(nums[i], nums[j]);
      } else {
        i++;
      }
    }
    for(i=0; i<nums.size(); i++) {
      if(i+1!=nums[i]) {
        return i+1;
      }
    }
    // cases such as [] and [1] etc
    return nums.size()+1;
  }
};

int main(int argc, char *argv[]) {
  vector<int> v1 = {-3, 1, 5, 4, 2};
  cout << FirstMissingPositive::findNumber(v1) << endl;

  v1 = {3, -2, 0, 1, 2};
  cout << FirstMissingPositive::findNumber(v1) << endl;

  v1 = {3, 2, 5, 1};
  cout << FirstMissingPositive::findNumber(v1) << endl;
}
