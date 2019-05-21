// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5718922095493120

#include<iostream>
#include<cstring>
using namespace std;

void match(string s1, string s2) {
  int N1=s1.size(), N2=s2.size(), i, j;
  int dp[N2+1][N1+1];
  for(j=0; j<=N1; j++) {
    dp[0][j] = 1;
  }
  for(i=1; i<=N2; i++) {
    for(j=1; j<=N1; j++) {
      dp[i][j] = 0;
      if(s2[i-1]==s1[j-1]) {
        dp[i][j] = dp[i-1][j-1];
      }
      dp[i][j] += dp[i][j-1];
    }
  }
  cout<<s1<<' '<<s2<<' '<<dp[N2][N1]<<'\n';
}

int main(void) {
  match("baxmx", "ax");
  match("tomorrow", "tor");
  return 0;
}