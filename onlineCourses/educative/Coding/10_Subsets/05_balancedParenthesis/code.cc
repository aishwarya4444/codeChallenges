// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5753264117121024

using namespace std;

#include <iostream>
#include <queue>
#include <string>
#include <vector>

class paranthesesString {
  public:
    string s;
    int open;
    int close;
    paranthesesString(string s, int open, int close) {
      this->s = s;
      this->open = open;
      this->close = close;
    }
};

class GenerateParentheses {
 public:
  static vector<string> generateValidParentheses(int num) {
    vector<string> result;
    // TODO: Write your code here
    queue<paranthesesString> q;
    paranthesesString ps({"", 0, 0});
    q.push(ps);
    while(q.size()) {
      ps = q.front();
      q.pop();
      if(ps.open < num) {
        q.push({ps.s+'(', ps.open+1, ps.close});
      }
      if(ps.close < ps.open) {
        q.push({ps.s+')', ps.open, ps.close+1});
      }
      if(ps.open == ps.close && ps.open == num) {
        result.push_back(ps.s);
      }
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  vector<string> result = GenerateParentheses::generateValidParentheses(2);
  cout << "All combinations of balanced parentheses are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;

  result = GenerateParentheses::generateValidParentheses(3);
  cout << "All combinations of balanced parentheses are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;
}
