// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5712536552865792

#include<iostream>
#include<vector>
using namespace std;

int findCount(vector<int> &num, int sum) {
  int i, s, N=num.size();
  int dp[N][sum+1];

  for(i=0; i<N; i++) {
    dp[i][0] = 1;
  }

  for(s=1; s<=sum; s++) {
    dp[0][s] = s==num[0];
  }

  for(i=1; i<N; i++) {
    for(s=1; s<=sum; s++) {
      dp[i][s] = dp[i-1][s];
      if(num[i]<=s) {
        dp[i][s] += dp[i-1][s-num[i]];
      }
    }
  }

  return dp[N-1][sum];
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
