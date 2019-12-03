// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5752754626625536

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

bool isSubsetPossible(vector<int> &num) {
  int i, sum = 0;

  for(i=0; i<num.size(); i++) {
    sum += num[i];
  }

  if(sum%2) {
    return false;
  }

  return isPossible(num, sum/2, 0);
}

int main(void) {
  vector<int> num;

  // Numbers
  num.push_back(1);
  num.push_back(1);
  num.push_back(3);
  num.push_back(4);
  num.push_back(7);

  cout<<isSubsetPossible(num)<<'\n';

  return 0;
}