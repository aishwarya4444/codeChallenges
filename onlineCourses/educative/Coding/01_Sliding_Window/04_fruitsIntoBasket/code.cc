// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5239377766645760

using namespace std;

#include <iostream>
#include <unordered_map>
#include <vector>

// https://leetcode.com/problems/fruit-into-baskets/

class MaxFruitCountOf2Types {
 public:
  static int findLength(const vector<char>& arr) {
    int maxLength = 0;
    // TODO: Write your code here
    int start=0, end=0, N=arr.size();
    unordered_map<char, int> m;
    for(end=0; end<N; end++) {
      m[arr[end]]++;
      while((int)m.size()>2) {
        m[arr[start]]--;
        if(m[arr[start]]==0) {
          m.erase(arr[start]);
        }
        start++;
      }
      maxLength=max(maxLength, end-start+1);
    }
    return maxLength;
  }
};

int main(int argc, char* argv[]) {
  cout << "Maximum number of fruits: "
       << MaxFruitCountOf2Types::findLength(vector<char>{'A', 'B', 'C', 'A', 'C'}) << endl;
  cout << "Maximum number of fruits: "
       << MaxFruitCountOf2Types::findLength(vector<char>{'A', 'B', 'C', 'B', 'B', 'C'}) << endl;
}
