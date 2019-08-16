// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5698217712812032

using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

// https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/

class LongestSubstringKDistinct {
 public:
  static int findLength(const string& str, int k) {
    int maxLength = 0;
    // TODO: Write your code here
    int start = 0, end = 0, unique = 0, N = str.size();
    unordered_map<char, int> m;
    // while(end < N) {
    //   // if(m.find(str[end]) == m.end() || m[str[end]]==0) {
    //   if(m[str[end]]==0) {
    //     unique++;
    //   }
    //   m[str[end]]++;
    //   if(unique<=k) {
    //     maxLength = max(maxLength, end-start+1);
    //   }
    //   while(unique>k) {
    //     m[str[start]]--;
    //     if(m[str[start]]==0) {
    //       unique--;
    //     }
    //     start++;
    //   }
    //   end++;
    // }
    for(end=0; end<N; end++) {
      m[str[end]]++;
      while((int)m.size()>k) {
        m[str[start]]--;
        if(m[str[start]]==0) {
          m.erase(str[start]);
        }
        start++;
      }
      maxLength = max(maxLength, end-start+1);
    }
    return maxLength;
  }
};

int main(int argc, char* argv[]) {
  cout << "Length of the longest substring: " << LongestSubstringKDistinct::findLength("araaci", 2) << endl;
  cout << "Length of the longest substring: " << LongestSubstringKDistinct::findLength("araaci", 1) << endl;
  cout << "Length of the longest substring: " << LongestSubstringKDistinct::findLength("cbbebi", 3) << endl;
}
