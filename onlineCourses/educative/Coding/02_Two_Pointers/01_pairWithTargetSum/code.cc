// https://www.educative.io/collection/page/5668639101419520/5671464854355968/6618310940557312

using namespace std;

#include <iostream>
#include <vector>

class PairWithTargetSum {
 public:
  static pair<int, int> search(const vector<int>& arr, int targetSum) {
    int j=arr.size()-1, i=0, a=-1, b=-1;
    while(i<j) {
      if(arr[i]+arr[j]==targetSum) {
        a=i;
        b=j;
        break;
      }
      if(arr[i]+arr[j]>targetSum) j--;
      else i++;
    }
    return make_pair(a,b);
  }
};

int main(int argc, char* argv[]) {
  auto result = PairWithTargetSum::search(vector<int>{1, 2, 3, 4, 6}, 6);
  cout << "Pair with target sum: [" << result.first << ", " << result.second << "]" << endl;
  result = PairWithTargetSum::search(vector<int>{2, 5, 9, 11}, 11);
  cout << "Pair with target sum: [" << result.first << ", " << result.second << "]" << endl;
}
