// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5718922095493120

#include<iostream>
#include<cstring>
using namespace std;

void match(string s1, string s2) {
  int N1=s1.size(), N2=s2.size(), i, j;
  int dp[N1+1][N2+1];

  for(i=0; i<=N1; i++) {
    dp[i][0] = 1;
  }

  for(j=1; j<=N2; j++) {
    dp[0][j] = 0;
  }

  for(i=1; i<=N1; i++) {
    for(j=1; j<=N2; j++) {
      dp[i][j] = 0;
      if(s1[i-1]==s2[j-1]) {
        dp[i][j] = dp[i-1][j-1];
      }
      dp[i][j] += dp[i-1][j];
    }
  }
  cout<<s1<<' '<<s2<<' '<<dp[N1][N2]<<'\n';
}

int main(void) {
  match("baxmx", "ax");
  match("tomorrow", "tor");
  return 0;
}