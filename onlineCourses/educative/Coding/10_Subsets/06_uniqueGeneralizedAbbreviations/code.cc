// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5646748928180224

using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <vector>

class AbbreviatedWord {
 public:
  string str;
  int start = 0;
  int count = 0;

  AbbreviatedWord(string str, int start, int count) {
    this->str = str;
    this->start = start;
    this->count = count;
  }
};

// https://leetcode.com/problems/generalized-abbreviation/

class GeneralizedAbbreviation {
 public:
  static vector<string> generateGeneralizedAbbreviation(const string &word) {
    vector<string> result;
    // TODO: Write your code here
    AbbreviatedWord aw({"", 0, 0});
    queue<AbbreviatedWord> q;
    q.push(aw);
    while(q.size()) {
      aw = q.front();
      q.pop();
      if(aw.start == word.size()) {
        if(aw.count) {
          aw.str += to_string(aw.count);
        }
        result.push_back(aw.str);
      } else {
        q.push({aw.str, aw.start+1, aw.count+1});
        if(aw.count) {
          aw.str += to_string(aw.count);
        }
        aw.str += word[aw.start];
        q.push({aw.str, aw.start+1, 0});
      }
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  vector<string> result = GeneralizedAbbreviation::generateGeneralizedAbbreviation("BAT");
  cout << "Generalized abbreviation are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;

  result = GeneralizedAbbreviation::generateGeneralizedAbbreviation("code");
  cout << "Generalized abbreviation are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;
}
