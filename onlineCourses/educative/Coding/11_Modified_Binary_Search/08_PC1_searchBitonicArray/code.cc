// https://www.educative.io/courses/grokking-the-coding-interview/mEGORlpZYJE

using namespace std;

#include <iostream>
#include <vector>

class SearchBitonicArray {
 public:
  static int binarySearch(const vector<int> &a, int key, int l, int r) {
    int m;
    bool ascending = a[l]<a[r];
    while(l<=r) {
      m = l+(r-l)/2;
      if(a[m]==key) {
        return m;
      }
      if(ascending) {
        if(key<a[m]) {
          r = m-1;
        } else {
          l = m+1;
        }
      } else {
        if(key<a[m]) {
          l = m+1;
        } else {
          r = m-1;
        }
      }
    }
    return -1;
  }
  static int search(const vector<int> &arr, int key) {
    // TODO: Write your code here

    // find max index
    int N=arr.size(), l=0, m, r=N-1, index, result;
    while(l<r) {
      m = l+(r-l)/2;
      if(arr[m]>arr[m+1]) {
        r = m;
      } else {
        l = m+1;
      }
    }
    index = l;

    // binary search for ascending
    result = binarySearch(arr, key, 0, index);
    if(result != -1) {
      return result;
    }

    // binary serach descending
    result = binarySearch(arr, key, index+1, N-1);
    return result;
  }
};

int main(int argc, char *argv[]) {
  cout << SearchBitonicArray::search(vector<int>{1, 3, 8, 4, 3}, 4) << endl;
  cout << SearchBitonicArray::search(vector<int>{3, 8, 3, 1}, 8) << endl;
  cout << SearchBitonicArray::search(vector<int>{1, 3, 8, 12}, 12) << endl;
  cout << SearchBitonicArray::search(vector<int>{10, 9, 8}, 10) << endl;
}
