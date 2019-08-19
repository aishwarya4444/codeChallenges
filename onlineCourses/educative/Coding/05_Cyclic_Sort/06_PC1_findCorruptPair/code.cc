// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5084962401288192

using namespace std;

#include <iostream>
#include <string>
#include <vector>

class FindCorruptNums {
 public:
  static vector<int> findNumbers(vector<int> &nums) {
    // TODO: Write your code here
    int i=0, j;
    while(i<nums.size()) {
      j = nums[i]-1;
      if(nums[i]==nums[j]) {
        i++;
      } else {
        swap(nums[i], nums[j]);
      }
    }
    for(i=0; i<nums.size(); i++) {
      if(i+1!=nums[i]) {
        return vector<int>{nums[i], i+1};
      }
    }
    return vector<int>{-1, -1};
  }
};

int main(int argc, char *argv[]) {
  vector<int> v1 = {3, 1, 2, 5, 2};
  vector<int> nums = FindCorruptNums::findNumbers(v1);
  cout << nums[0] << ", " << nums[1] << endl;

  v1 = {3, 1, 2, 3, 6, 4};
  nums = FindCorruptNums::findNumbers(v1);
  cout << nums[0] << ", " << nums[1] << endl;
}
