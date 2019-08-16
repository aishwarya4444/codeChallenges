// https://www.educative.io/collection/page/5668639101419520/5671464854355968/6497958910492672

using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

// https://leetcode.com/problems/longest-repeating-character-replacement/

class CharacterReplacement {
 public:
  static int findLength(const string& str, int k) {
    int maxLength = 0;
    // TODO: Write your code here
    int start=0, end=0, N=str.size(), maxFreq=0;
    unordered_map<char, int> m;
    for(end=0; end<N; end++) {
      m[str[end]]++;
      maxFreq = max(maxFreq, m[str[end]]);
      if(end-start+1-maxFreq > k) {
        m[str[start]]--;
        start++;
      }
      maxLength = max(maxLength, end-start+1);
    }
    return maxLength;
  }
};

int main(int argc, char* argv[]) {
  cout << CharacterReplacement::findLength("aabccbb", 2) << endl;
  cout << CharacterReplacement::findLength("abbcb", 1) << endl;
  cout << CharacterReplacement::findLength("abccde", 1) << endl;
}
