// https://www.educative.io/courses/grokking-the-coding-interview/B1ZW38kXJB2

using namespace std;

#include <iostream>
#include <limits>
#include <vector>

// https://leetcode.com/problems/search-in-a-sorted-array-of-unknown-size/

class ArrayReader {
 public:
  vector<int> arr;

  ArrayReader(const vector<int> &arr) { this->arr = arr; }

  virtual int get(int index) {
    if (index >= arr.size()) {
      return numeric_limits<int>::max();
    }
    return arr[index];
  }
};

class SearchInfiniteSortedArray {
 public:
  static int search(ArrayReader *reader, int key) {
    // TODO: Write your code here
    int l=0, m, r=1, value;
    while(target > reader.get(r)) {
      l = r;
      r <<= 1;
    }
    while(l<=r) {
      m = l + (r-l)/2;
      value = reader->get(m);
      if(value == key) {
        return m;
      }
      if(key < value) {
        r = m-1;
      } else {
        l = m+1;
      }
    }
    return -1;
  }
};

int main(int argc, char *argv[]) {
  ArrayReader *reader =
      new ArrayReader(vector<int>{4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30});
  cout << SearchInfiniteSortedArray::search(reader, 16) << endl;
  cout << SearchInfiniteSortedArray::search(reader, 11) << endl;
  reader = new ArrayReader(vector<int>{1, 3, 8, 10, 15});
  cout << SearchInfiniteSortedArray::search(reader, 15) << endl;
  cout << SearchInfiniteSortedArray::search(reader, 200) << endl;
  delete reader;
}
