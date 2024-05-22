// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5784530449334272
// https://leetcode.com/problems/sort-colors/description/

using namespace std;

#include <iostream>
#include <vector>

class DutchFlag {
 public:
  static void swap(vector<int> &arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
  static void sort(vector<int> &arr) {
    // TODO: Write your code here
    int start=0, mid=0, end=arr.size()-1;
    while(mid <= end) {
      if(arr[mid] == 0) {
        swap(arr, start, mid);
        start++;
        mid++;
      } else if(arr[mid] == 1) {
        mid++;
      } else {
        swap(arr, mid, end);
        end--;
      }
    }
  }
};

int main(int argc, char *argv[]) {
  vector<int> arr = {1, 0, 2, 1, 0};
  DutchFlag::sort(arr);
  for (auto num : arr) {
    cout << num << " ";
  }
  cout << endl;

  arr = vector<int>{2, 2, 0, 1, 2, 0};
  DutchFlag::sort(arr);
  for (auto num : arr) {
    cout << num << " ";
  }
}
