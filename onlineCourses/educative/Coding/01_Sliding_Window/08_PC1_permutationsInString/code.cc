// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5401934796161024

using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

// https://leetcode.com/problems/permutation-in-string/

class StringPermutation {
 public:
  static bool findPermutation(const string &str, const string &pattern) {
    // TODO: Write your code here
    int start=0, end, N=str.size(), match=0;
    unordered_map<char, int> patternFreq;
    for(char chr: pattern) {
      patternFreq[chr]++;
    }
    for(end=0; end<N; end++) {
      if(patternFreq.find(str[end]) != patternFreq.end()) {
        patternFreq[str[end]]--;
        if(patternFreq[str[end]] == 0) {
          match++;
        }
        if(match == (int)patternFreq.size()) {
          return true;
        }
      }
      if(end+1 >= pattern.size()) {
        if(patternFreq.find(str[start]) != patternFreq.end()) {
          if(patternFreq[str[start]]==0) {
            match--;
          }
          patternFreq[str[start]]++;
        }
        start++;
      }
    }
    return false;
  }
};

int main(int argc, char *argv[]) {
  cout << "Permutation exist: " << StringPermutation::findPermutation("oidbcaf", "abc") << endl;
  cout << "Permutation exist: " << StringPermutation::findPermutation("odicf", "dc") << endl;
  cout << "Permutation exist: " << StringPermutation::findPermutation("bcdxabcdy", "bcdyabcdx") << endl;
  cout << "Permutation exist: " << StringPermutation::findPermutation("aaacb", "abc") << endl;
}
