// https://www.educative.io/collection/page/5668639101419520/5671464854355968/6005911854252032

using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

// https://leetcode.com/problems/find-all-anagrams-in-a-string/

class StringAnagrams {
 public:
  static vector<int> findStringAnagrams(const string &str, const string &pattern) {
    vector<int> resultIndices;
    // TODO: Write your code here
    int start=0, end, S=str.size(), P=pattern.size(), match=0;
    unordered_map<char, int> freqMap;
    for(char chr: pattern) {
      freqMap[chr]++;
    }
    for(end=0; end<S; end++) {
      if(freqMap.find(str[end]) != freqMap.end()) {
        freqMap[str[end]]--;
        if(freqMap[str[end]] == 0) {
          match++;
        }
        if(match == (int)freqMap.size()) {
          resultIndices.push_back(start);
        }
      }
      if(end+1 >= P) {
        if(freqMap.find(str[start]) != freqMap.end()) {
          if(freqMap[str[start]] == 0) {
            match--;
          }
          freqMap[str[start]]++;
        }
        start++;
      }
    }
    return resultIndices;
  }
};

int main(int argc, char *argv[]) {
  auto result = StringAnagrams::findStringAnagrams("ppqp", "pq");
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = StringAnagrams::findStringAnagrams("abbcabc", "abc");
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}
