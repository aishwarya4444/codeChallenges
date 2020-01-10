// https://www.educative.io/collection/page/5668639101419520/5671464854355968/5712272949248000

using namespace std;

#include <cctype>
#include <iostream>
#include <string>
#include <vector>

class EvaluateExpression {
 public:
  static vector<int> diffWaysToEvaluateExpression(const string& input) {
    vector<int> result;
    // TODO: Write your code here
    vector<int> leftParts, rightParts;
    int i;

    if(input.find('+')==string::npos && input.find('-')==string::npos && input.find('*')==string::npos) {
      result.push_back(stoi(input));
      return result;
    }
    
    for(i=0; i<input.size(); i++) {
      if(input[i]>=48 && input[i]<=57) {
        continue;
      }
      leftParts = diffWaysToEvaluateExpression(input.substr(0, i));
      rightParts = diffWaysToEvaluateExpression(input.substr(i+1));
      for(auto left: leftParts) {
        for(auto right: rightParts) {
          if(input[i] == '+') {
            result.push_back(left+right);
          } else if(input[i] == '-') {
            result.push_back(left-right);
          } else if(input[i] == '*') {
            result.push_back(left*right);
          }
        }
      }
    }
    return result;
  }

};

int main(int argc, char* argv[]) {
  vector<int> result = EvaluateExpression::diffWaysToEvaluateExpression("1+2*3");
  cout << "Expression evaluations: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = EvaluateExpression::diffWaysToEvaluateExpression("2*3-4-5");
  cout << "Expression evaluations: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}
