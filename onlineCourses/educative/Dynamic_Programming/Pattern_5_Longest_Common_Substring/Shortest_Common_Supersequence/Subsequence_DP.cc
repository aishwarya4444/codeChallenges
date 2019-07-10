// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5700866052980736

#include<iostream>
#include<cstring>
using namespace std;

int subsequence(string s1, string s2) {
  int N1=s1.size(), N2=s2.size(), i, j;
  int dp[N1+1][N2+1];
  for(i=0; i<=N1; i++) {
    dp[i][0] = i;
  }
  for(j=0; j<=N2; j++) {
    dp[0][j] = j;
  }
  for(i=1; i<=N1; i++) {
    for(j=1; j<=N2; j++) {
      dp[i][j] = 0;
      if(s1[i-1] == s2[j-1]) {
        dp[i][j] = 1+dp[i-1][j-1];
      } else {
        dp[i][j] = 1+min(dp[i-1][j], dp[i][j-1]);
      }
    }
  }
  return dp[N1][N2];
}

int main(void) {
  cout<<subsequence("abcf", "bdcf")<<'\n';
  cout<<subsequence("dynamic", "programming")<<'\n';
  return 0;
}
