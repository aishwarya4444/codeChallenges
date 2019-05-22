// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5698125863845888

#include<iostream>
#include<cstring>
using namespace std;

int deletions(string &s) {
  int N=s.size(), l, r, length=0;
  int dp[N][N];
  for(l=0; l<N; l++) {
    dp[l][l] = 1;
  }
  for(l=N-1; l>=0; l--) {
    for(r=l+1; r<N; r++) {
      dp[l][r] = 0;
      if(s[l] == s[r]) {
        dp[l][r] = 2 + dp[l+1][r-1];
      } else {
        dp[l][r] = max(dp[l+1][r], dp[l][r-1]);
      }
    }
  }
  return N-dp[0][N-1];
}

int main(void ) {
  string s("abdbca");
  cout<<deletions(s)<<'\n';

  s = "cddpd";
  cout<<deletions(s)<<'\n';

  s = "pqr";
  cout<<deletions(s)<<'\n';

  return 0;
}