// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5686812383117312

using namespace std;

#include <iostream>
#include <string>
#include <vector>
#include <queue>
class LetterCaseStringPermutation {
 public:
  static vector<string> findLetterCaseStringPermutations(const string& str) {
    vector<string> permutations;
    // TODO: Write your code here
    int i, N;
    queue<string> q;
    string temp = "";
    char letter;
    q.push(temp);
    for(i=0; i<str.size(); i++) {
      N = q.size();
      while(N--) {
        temp = q.front();
        q.pop();
        letter = str[i];
        if(letter>=97 && letter<=122) {
          q.push(temp + letter);
          letter -= 32;
          q.push(temp + letter);
        } else if(letter>=65 && letter<=90) {
          q.push(temp + letter);
          letter += 32;
          q.push(temp + letter);
        } else {
          q.push(temp + letter);
        }
      }
    }
    while(q.size()) {
      permutations.push_back(q.front());
      q.pop();
    }
    return permutations;
  }
};

int main(int argc, char* argv[]) {
  vector<string> result = LetterCaseStringPermutation::findLetterCaseStringPermutations("ad52");
  cout << "String permutations are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;

  result = LetterCaseStringPermutation::findLetterCaseStringPermutations("ab7c");
  cout << "String permutations are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;
}
