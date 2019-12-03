// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5752754626625536

#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int> &num, int sum) {
  int i, s, N = num.size();
  bool dp[N][sum+1];

  for(i=0; i<N; i++) {
    dp[i][0] = true;
  }

  for(s=1; s<=sum; s++) {
    dp[0][s] = num[0]==s;
  }

  for(i=1; i<N; i++) {
    for(s=1; s<=sum; s++) {
      if(dp[i-1][s]) {
        dp[i][s] = dp[i-1][s];
      } else if(num[i]<=s) {
        dp[i][s] = dp[i-1][s-num[i]];
      }
    }
  }

  return dp[N-1][sum];
}

bool isSubsetPossible(vector<int> &num) {
  int i, sum = 0;

  for(i=0; i<num.size(); i++) {
    sum += num[i];
  }

  if(sum%2) {
    return false;
  }

  return isPossible(num, sum/2);
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