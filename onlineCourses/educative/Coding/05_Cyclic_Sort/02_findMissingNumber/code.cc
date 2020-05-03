// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5319932059320320

#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.com/problems/missing-number/

class MissingNumber {
 public:
  static int findMissingNumber(vector<int> &nums) {
    // TODO: Write your code here
    int i=0, j;
    while(i < nums.size()) {
      j = nums[i];
      if(j>=0 && j<nums.size() && nums[i]!=nums[j]) {
        swap(nums[i], nums[j]);
      } else {
        i++;
      }
    }
    for(i=0; i<nums.size(); i++) {
      cout<<nums[i]<<' ';
    }
    cout<<endl;
    for(i=0; i<nums.size(); i++) {
      if(i!=nums[i]) {
        return i;
      }
    }
    return -1;
  }
};

int main(int argc, char *argv[]) {
  vector<int> v1 = {4, 0, 3, 1};
  cout << MissingNumber::findMissingNumber(v1) << endl;
  v1 = {8, 3, 5, 2, 4, 6, 0, 1};
  cout << MissingNumber::findMissingNumber(v1) << endl;
}
