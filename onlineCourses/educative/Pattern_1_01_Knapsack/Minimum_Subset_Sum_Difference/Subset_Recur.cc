// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5695872079757312

#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> & num, int i, int sum1, int sum2) {
  if(i==num.size()) {
    return sum1>sum2 ? sum1-sum2 : sum2-sum1;
  }

  int diff1, diff2;

  diff1 = solve(num, i+1, sum1+num[i], sum2);
  diff2 = solve(num, i+1, sum1, sum2+num[i]);

  return min(diff1, diff2);
}

int getDiff(vector<int> &num) {
  return solve(num, 0, 0, 0);
}

int main(void) {
  vector<int> num;

  // Numbers
  num.push_back(1);
  num.push_back(3);
  num.push_back(100);
  num.push_back(4);

  cout<<getDiff(num);

  return 0;
}