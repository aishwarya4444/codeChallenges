// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5646239437684736

#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int> &num, int sum) {
  int i, s, N = num.size();
  bool dp[N][sum+1];

  for(i=0; i<N; i++) {
    dp[0][i] = true;
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

bool isSubsetPossible(vector<int> &num, int sum) {
  int i, N=num.size(), s;
  int dp[N][sum+1];

  for(i=0; i<N; i++) {
    dp[i][0] = true;
  }

  for(s=1; s<=sum; s++) {
    dp[0][s] = s==num[0];
  }

  for(i=1; i<N; i++) {
    for(s=1; s<=sum; s++) {
      if(dp[i-1][s]) {
        dp[i][s] = true;
      } else if(num[i]<=s) {
        dp[i][s] = dp[i-1][s-num[i]];
      }
    }
  }

  return dp[N-1][s];
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