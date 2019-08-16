// https://www.educative.io/collection/page/5668639101419520/5671464854355968/4559641746866176

using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

// https://leetcode.com/problems/substring-with-concatenation-of-all-words/

class WordConcatenation {
 public:
  static vector<int> findWordConcatenation(const string &str, const vector<string> &words) {
    vector<int> resultIndices;
    // TODO: Write your code here
    int start=0, end, S=str.size(), W=words.size(), wordSize;
    unordered_map<string, int> freqPat, freqStr;
    string word;
    if(!S || !W) {
      return resultIndices;
    }
    for(string word: words) {
      freqPat[word]++;
    }
    wordSize = words[0].size();
    for(start=0; start<=S-W*wordSize; start++) {
      freqStr.clear();
      for(end=start; end<start+W*wordSize; end+=wordSize) {
        word = str.substr(end, wordSize);
        if(freqPat.find(word) == freqPat.end()) {
          break;
        }
        freqStr[word]++;
        if(freqStr[word] > freqPat[word]) {
          break;
        }
        if(end+wordSize == start+W*wordSize) {
          resultIndices.push_back(start);
        }
      }
    }
    return resultIndices;
  }
};

int main(int argc, char *argv[]) {
  vector<int> result =
      WordConcatenation::findWordConcatenation("catfoxcat", vector<string>{"cat", "fox"});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = WordConcatenation::findWordConcatenation("catcatfoxfox", vector<string>{"cat", "fox"});
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}
