// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5750031617359872

#include<iostream>
#include<cstring>
using namespace std;

// https://leetcode.com/problems/maximum-length-of-repeated-subarray/

int substring(string s1, string s2) {
  int N1=s1.size(), N2=s2.size(), i, j;
  int dp[N1+1][N2+1], length=0;
  for(i=0; i<=N1; i++) {
    dp[i][0] = 0;
  }
  for(j=0; j<=N2; j++) {
    dp[0][j] = 0;
  }
  for(i=1; i<=N1; i++) {
    for(j=1; j<=N2; j++) {
      dp[i][j] = 0;
      if(s1[i-1] == s2[j-1]) {
        dp[i][j] = 1+dp[i-1][j-1];
        length = max(length, dp[i][j]);
      }
    }
  }
  return length;
}

int main(void) {
  cout<<substring("abdca", "cbda")<<'\n';
  cout<<substring("passport", "ppsspt")<<'\n';
  return 0;
}