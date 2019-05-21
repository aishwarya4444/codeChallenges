// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5724313353191424

#include<iostream>
using namespace std;

int factors(int n) {
  int i, dp[n+1];
  dp[0] = dp[1] = dp[2] = 1;
  dp[3] = 2;
  for(i=4; i<=n; i++) {
    dp[i] = dp[i-1] + dp[i-3] + dp[i-4];
  }
  return dp[n];
}

int main(void) {
  cout<<factors(4)<<'\n';
  cout<<factors(5)<<'\n';
  cout<<factors(6)<<'\n';

  return 0;
}