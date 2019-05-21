// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5646239437684736

#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int> &num, int sum, int i) {
  if(sum==0) {
    return true;
  }

  if(i==num.size()) {
    return false;
  }

  if(num[i]<=sum) {
    if(isPossible(num, sum-num[i], i+1)) {
      return true;
    }
  }

  return isPossible(num, sum, i+1);
}

bool isSubsetPossible(vector<int> &num, int sum) {
  return isPossible(num, sum, 0);
}

int main(void) {
  vector<int> num;

  // Numbers
  num.push_back(1);
  num.push_back(2);
  num.push_back(3);
  num.push_back(7);

  cout<<isSubsetPossible(num, 10)<<'\n';

  return 0;
}