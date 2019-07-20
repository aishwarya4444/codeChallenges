// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5679413765079040

#include<iostream>
#include<vector>
using namespace std;

int targetSum(vector<int> &num, int sum) {
  int N=num.size(), i, s;
  for(i=0; i<N; i++) {
    sum += num[i];
  }
  if(sum%2) {
    return 0;
  }

  sum/=2;

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