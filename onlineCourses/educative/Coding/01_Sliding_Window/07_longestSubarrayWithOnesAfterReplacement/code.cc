// https://www.educative.io/collection/page/5668639101419520/5671464854355968/4867522786492416

using namespace std;

#include <iostream>
#include <vector>

// https://leetcode.com/problems/max-consecutive-ones-ii/
// https://leetcode.com/problems/max-consecutive-ones-iii/

class ReplacingOnes {
 public:
  static int findLength(const vector<int>& arr, int k) {
    int  maxLength = 0;
    // TODO: Write your code here
    int start=0, end, N=arr.size(), countOne=0;
    for(end=0; end<N; end++) {
      if(arr[end]) {
        countOne++;
      }
      if(end-start+1-countOne > k) {
        if(arr[start]) {
          countOne--;
        }
        start++;
      }
      maxLength=max(maxLength, end-start+1);
    }
    return maxLength;
  }
};

int main(int argc, char* argv[]) {
  cout << ReplacingOnes::findLength(vector<int>{0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1}, 2) << endl;
  cout << ReplacingOnes::findLength(vector<int>{0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1}, 3) << endl;
}
