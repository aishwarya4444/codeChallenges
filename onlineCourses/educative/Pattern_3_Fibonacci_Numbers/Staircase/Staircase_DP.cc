// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5649202965118976

#include<iostream>
using namespace std;

int stairs(int n) {
  int i, dp[n+1];
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;

  for(i=3; i<=n; i++) {
    dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
  }

  return dp[n];
}

int main(void) {
  cout<<stairs(3)<<'\n';
  cout<<stairs(4)<<'\n';
  cout<<stairs(5)<<'\n';
  return 0;
}