// https://www.educative.io/collection/page/5668639101419520/5671464854355968/4739274459054080

using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

// https://leetcode.com/problems/minimum-window-substring/

class MinimumWindowSubstring {
 public:
  static string findPermutation(const string &str, const string &pattern) {
    // TODO: Write your code here
    int start=0, end, S=str.size(), P=pattern.size(), match=0, length=S+1, substrStart=-1;
    unordered_map<char, int> freqMap;
    for(char chr: pattern) {
      freqMap[chr]++;
    }
    for(end=0; end<S; end++) {
      if(freqMap.find(str[end]) != freqMap.end()) {
        freqMap[str[end]]--;
        if(freqMap[str[end]] >= 0) {
          match++;
        }
      }
      while(match == P) {
        if(length > end-start+1) {
          length = end-start+1;
          substrStart = start;
        }
        if(freqMap.find(str[start]) != freqMap.end()) {
          if(freqMap[str[start]] == 0) {
            match--;
          }
          freqMap[str[start]]++;
        }
        start++;
      }
    }
    return substrStart==-1 ? "" : str.substr(substrStart, length);
  }
};

int main(int argc, char *argv[]) {
  cout << MinimumWindowSubstring::findPermutation("aabdec", "abc") << endl;
  cout << MinimumWindowSubstring::findPermutation("abdabca", "abc") << endl;
  cout << MinimumWindowSubstring::findPermutation("adcad", "abc") << endl;
}
