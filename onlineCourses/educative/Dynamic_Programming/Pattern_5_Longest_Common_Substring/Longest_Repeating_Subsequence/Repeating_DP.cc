// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5653294995210240

#include<iostream>
#include<cstring>
using namespace std;

void repeating(string s) {
  int N=s.size(), i, j, length=0;
  int dp[N+1][N+1];
  for(i=0; i<=N; i++) {
    dp[0][i] = dp[i][0] = 0;
  }
  for(i=1; i<=N; i++) {
    for(j=1; j<=N; j++) {
      if(i!=j && s[i-1]==s[j-1]) {
        dp[i][j] = 1+dp[i-1][j-1];
      } else {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
      length = max(length, dp[i][j]);
    }
  }
  cout<<s<<' '<<length<<'\n';
}

int main(void) {
  repeating("tomorrow");
  repeating("aabdbcec");
  repeating("fmff");
  return 0;
}