// https://www.educative.io/courses/grokking-the-coding-interview/qA5wW7R8ox7

using namespace std;

#include <iostream>
#include <vector>

class CeilingOfANumber {
 public:
  static int searchCeilingOfANumber(const vector<int>& arr, int key) {
    // TODO: Write your code here
    int l=0, r=arr.size()-1, m;
    if(key>arr[r]) {
      return -1;
    }
    while(l<=r) {
      m=l+(r-l)/2;
      if(key == arr[m]) {
        return m;
      } else if(key<arr[m]) {
        r = m-1;
      } else {
        l = m+1;
      }
    }
    return l;
  }
};

int main(int argc, char* argv[]) {
  cout << CeilingOfANumber::searchCeilingOfANumber(vector<int>{4, 6, 10}, 6) << endl;
  cout << CeilingOfANumber::searchCeilingOfANumber(vector<int>{1, 3, 8, 10, 15}, 12) << endl;
  cout << CeilingOfANumber::searchCeilingOfANumber(vector<int>{4, 6, 10}, 17) << endl;
  cout << CeilingOfANumber::searchCeilingOfANumber(vector<int>{4, 6, 10}, -1) << endl;
}
