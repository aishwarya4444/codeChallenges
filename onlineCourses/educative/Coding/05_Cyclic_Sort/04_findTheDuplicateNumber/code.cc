// https://www.educative.io/collection/page/5668639101419520/5671464854355968/4522012447866880

using namespace std;

#include <iostream>
#include <vector>

// https://leetcode.com/problems/find-the-duplicate-number/

class FindDuplicate {
 public:
  static int findNumber(vector<int> &nums) {
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
        return nums[i];
      }
    }
    return -1;
  }
};

int main(int argc, char *argv[]) {
  vector<int> v1 = {1, 4, 4, 3, 2};
  cout << FindDuplicate::findNumber(v1) << endl;

  v1 = {2, 1, 3, 3, 5, 4};
  cout << FindDuplicate::findNumber(v1) << endl;

  v1 = {2, 4, 1, 4, 4};
  cout << FindDuplicate::findNumber(v1) << endl;
}
