// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5727950116749312

#include<iostream>
#include<cstring>
using namespace std;

int substring(string &s) {
  int N=s.size(), l, r, count=0;
  bool dp[N][N];
  for(l=0; l<N; l++) {
    dp[l][l] = true;
    count++;
  }
  for(l=N-1; l>=0; l--) {
    for(r=l+1; r<N; r++) {
      dp[l][r] = false;
      if(s[l]==s[r]) {
        if(l+1==r || dp[l+1][r-1]) {
          dp[l][r] = true;
          count++;
        }
      }
    }
  }
  return count;
}

int main(void) {
  string s("abdbca");
  cout<<substring(s)<<'\n';

  s="cddpd";
  cout<<substring(s)<<'\n';

  s="pqr";
  cout<<substring(s)<<'\n';

  return 0;
}