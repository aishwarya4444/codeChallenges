// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5070198568648704

using namespace std;

#include <iostream>
#include <vector>

class RemoveDuplicates {
 public:
  static int remove(vector<int>& arr) {
    // TODO: Write your code here
    int l=1, r, N=arr.size();
    for(r=1; r<N; r++) {
      if(arr[l-1] != arr[r]) {
        arr[l] = arr[r];
        l++;
      }
    }
    return l;
  }
};

int main(int argc, char* argv[]) {
  vector<int> arr = {2, 3, 3, 3, 6, 9, 9};
  cout << "Array new length: " << RemoveDuplicates::remove(arr) << endl;

  arr = vector<int>{2, 2, 2, 11};
  cout << "Array new length: " << RemoveDuplicates::remove(arr) << endl;
}
