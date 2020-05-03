// https://www.educative.io/collection/page/5668639101419520/5671464854355968/6003980930908160

using namespace std;

#include <iostream>
#include <vector>

class CyclicSort {
  public:
    static void sort(vector<int> &nums) {
      // TODO: Write your code here
      int i=0, j;
      while(i < nums.size()) {
        j = nums[i]-1;
        if(j>=0 && j<nums.size() && nums[i]!=nums[j]) {
          swap(nums[i], nums[j]);
        } else {
          i++;
        }
      }
    }
};

int main(int argc, char *argv[]) {
  vector<int> arr = {3, 1, 5, 4, 2};
  CyclicSort::sort(arr);
  for (auto num : arr) {
    cout << num << " ";
  }
  cout << endl;

  arr = vector<int>{2, 6, 4, 3, 1, 5};
  CyclicSort::sort(arr);
  for (auto num : arr) {
    cout << num << " ";
  }
  cout << endl;
}
