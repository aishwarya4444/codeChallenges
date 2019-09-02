// https://www.educative.io/courses/grokking-the-coding-interview/mymvP915LY9

using namespace std;

#include <iostream>
#include <vector>

class MinimumDifference {
 public:
  static int searchMinDiffElement(const vector<int>& arr, int key) {
    // TODO: Write your code here
    int l=0, m, r=arr.size()-1;
    if(key <= arr[l]) {
      return arr[l];
    }
    if(key >= arr[r]) {
      return arr[r];
    }
    while(l<=r) {
      m = l+(r-l)/2;
      if(arr[m]==key) {
        return 0;
      }
      if(key < arr[m]) {
        r = m-1;
      } else {
        l = m+1;
      }
    }
    // l equal to r+1 after while loop
    if(key-arr[r] < arr[l]-key) {
      return arr[r];
    } else {
      return arr[l];
    }
  }
};

int main(int argc, char* argv[]) {
  cout << MinimumDifference::searchMinDiffElement(vector<int>{4, 6, 10}, 7) << endl;
  cout << MinimumDifference::searchMinDiffElement(vector<int>{4, 6, 10}, 4) << endl;
  cout << MinimumDifference::searchMinDiffElement(vector<int>{1, 3, 8, 10, 15}, 12) << endl;
  cout << MinimumDifference::searchMinDiffElement(vector<int>{4, 6, 10}, 17) << endl;
}
