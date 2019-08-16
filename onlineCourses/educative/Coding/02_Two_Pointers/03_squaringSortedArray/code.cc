// https://www.educative.io/collection/page/5668639101419520/5671464854355968/4873047792156672

using namespace std;

#include <iostream>
#include <vector>

class SortedArraySquares {
 public:
  static vector<int> makeSquares(const vector<int>& arr) {
    int n = arr.size();
    vector<int> squares(n);
    // TODO: Write your code here
    int l=0, r=n-1;
    while(l<=r) {
      if( abs(arr[l]) > abs(arr[r]) ) {
        squares[n-1] = arr[l]*arr[l];
        l++;
        n--;
      } else {
        squares[n-1] = arr[r]*arr[r];
        r--;
        n--;
      }
    }
    return squares;
  }
};

int main(int argc, char* argv[]) {
  vector<int> result = SortedArraySquares::makeSquares(vector<int>{-2, -1, 0, 2, 3});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = SortedArraySquares::makeSquares(vector<int>{-3, -1, 0, 1, 2});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}
