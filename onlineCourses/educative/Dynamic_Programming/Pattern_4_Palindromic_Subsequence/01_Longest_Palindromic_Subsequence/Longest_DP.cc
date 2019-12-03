// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5748119283171328

#include<iostream>
#include<cstring>
using namespace std;

int subsequence(string &s) {
  int N=s.size(), l, r;
  int dp[N][N];
  for(l=0; l<N; l++) {
    dp[l][l] = 1;
  }
  for(l=N-1; l>=0; l--) {
    for(r=l+1; r<N; r++) {
      if(s[l]==s[r]) {
        dp[l][r] = 2 + dp[l+1][r-1];
      } else {
        dp[l][r] = max(dp[l+1][r], dp[l][r-1]);
      }
    }
  }
  return dp[0][N-1];
//  for(l=0; l<N; l++) {
//    for(r=l-1; r>=0; r--) {
//      if(s[l]==s[r]) {
//        dp[l][r] = 2 + dp[l-1][r+1];
//      } else {
//        dp[l][r] = max(dp[l-1][r], dp[l][r+1]);
//      }
//    }
//  }
//  return dp[N-1][0];
}

int main(void) {
  string s("abdbca");
  cout<<subsequence(s)<<'\n';

  s="cddpd";
  cout<<subsequence(s)<<'\n';

  s="pqr";
  cout<<subsequence(s)<<'\n';

  return 0;
}
