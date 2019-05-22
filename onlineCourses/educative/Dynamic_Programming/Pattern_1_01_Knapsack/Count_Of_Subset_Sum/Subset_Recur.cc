// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5712536552865792

#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> &num, int sum, int i) {
  if(sum==0) {
    return 1;
  }

  if(i==num.size()) {
    return 0;
  }

  int freq = 0;
  if(sum>=num[i]) {
    freq = solve(num, sum-num[i], i+1);
  }
  return freq + solve(num, sum, i+1);
}

int findCount(vector<int> &num, int sum) {
  return solve(num, sum, 0);
}

int main(void) {
  vector<int> num;

  // numbers
  num.push_back(1);
  num.push_back(2);
  num.push_back(7);
  num.push_back(1);
  num.push_back(5);

  cout<<findCount(num, 9)<<'\n';

  return 0;
}
