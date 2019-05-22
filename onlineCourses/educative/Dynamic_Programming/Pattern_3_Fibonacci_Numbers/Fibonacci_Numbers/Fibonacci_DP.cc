// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5740874747084800

#include<iostream>
using namespace std;

int fib(int n) {
  int i, dp[n+1];
  dp[0] = 0;
  dp[1] = 1;

  for(i=2; i<=n; i++) {
    dp[i] = dp[i-1] + dp[i-2];
  }

  return dp[n];
}

int main(void) {
  cout<<fib(5)<<'\n';
  cout<<fib(6)<<'\n';
  cout<<fib(7)<<'\n';
  return 0;
}