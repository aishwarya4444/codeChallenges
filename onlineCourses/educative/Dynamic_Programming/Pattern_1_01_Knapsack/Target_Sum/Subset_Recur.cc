// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5679413765079040

#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> &num, int sum, int i) {
  if(sum==0 && i==num.size()) {
    return 1;
  }

  if(i==num.size()) {
    return 0;
  }

  return solve(num, sum+num[i], i+1) + solve(num, sum-num[i], i+1);
}

int targetSum(vector<int> &num, int sum) {
  return solve(num, sum, 0);
}

int main(void) {
  vector<int> num;

  // numbers
  num.push_back(1);
  num.push_back(1);
  num.push_back(2);
  num.push_back(3);

  cout<<targetSum(num, 1)<<'\n';

  // numbers
  num.clear();
  num.push_back(1);
  num.push_back(2);
  num.push_back(7);
  num.push_back(1);

  cout<<targetSum(num, 9)<<'\n';
}