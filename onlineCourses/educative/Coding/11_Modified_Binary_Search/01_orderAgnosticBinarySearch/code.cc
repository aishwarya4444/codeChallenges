// https://www.educative.io/courses/grokking-the-coding-interview/R8LzZQlj8lO

using namespace std;

#include <iostream>
#include <vector>

class BinarySearch {
 public:
  static int search(const vector<int>& arr, int key) {
    // TODO: Write your code here
    int l=0, r=arr.size()-1, m;
    bool ascendinng = arr[l]<arr[r];
    while(l<=r) {
      m = l + (r-l)/2;
      if(arr[m]==key) {
        return m;
      }
      if(ascendinng) {
        if(key<arr[m]) r=m-1;
        else l=m+1;
      } else {
        if(key<arr[m]) l=m+1;
        else r=m-1;
      }
    }
    return -1;
  }
};

int main(int argc, char* argv[]) {
  cout << BinarySearch::search(vector<int>{4, 6, 10}, 10) << endl;
  cout << BinarySearch::search(vector<int>{1, 2, 3, 4, 5, 6, 7}, 5) << endl;
  cout << BinarySearch::search(vector<int>{10, 6, 4}, 10) << endl;
  cout << BinarySearch::search(vector<int>{10, 6, 4}, 4) << endl;
}
