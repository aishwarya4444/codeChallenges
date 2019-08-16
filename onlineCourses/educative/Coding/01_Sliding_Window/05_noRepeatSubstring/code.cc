// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5485010335301632

using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class NoRepeatSubstring {
 public:
  static int findLength(const string& str) {
    int maxLength = 0;
    // TODO: Write your code here
    int start=0, end=0, N=str.size(), unique=0;
    unordered_map<char, int> m;
    // while(end<N) {
    //   if(m[str[end]]==0) {
    //     m[str[end]]++;
    //     maxLength=max(maxLength, end-start+1);
    //     end++;
    //   } else {
    //     m[str[start]]--;
    //     start++;
    //   }
    // }
    for(end=0; end<N; end++) {
      if(m.find(str[end])!=m.end()) {
        // this is tricky; in the current window, we will not have any 'rightChar' after its
        // previous index and if 'windowStart' is already ahead of the last index of 'rightChar',
        // we'll keep 'windowStart'
        start = max(start, m[str[end]]+1);
      }
      m[str[end]] = end;
      maxLength = max(maxLength, end-start+1);
    }
    return maxLength;
  }
};

int main(int argc, char* argv[]) {
  cout << "Length of the longest substring: " << NoRepeatSubstring::findLength("aabccbb") << endl;
  cout << "Length of the longest substring: " << NoRepeatSubstring::findLength("abbbb") << endl;
  cout << "Length of the longest substring: " << NoRepeatSubstring::findLength("abccde") << endl;
}
