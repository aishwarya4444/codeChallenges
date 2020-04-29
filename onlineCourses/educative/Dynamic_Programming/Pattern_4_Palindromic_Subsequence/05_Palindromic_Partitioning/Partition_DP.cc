// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5698125863845888

#include<iostream>
#include<cstring>
using namespace std;

// https://leetcode.com/problems/palindrome-partitioning/
// https://leetcode.com/problems/palindrome-partitioning-ii/

int partition(string &s) {
  int N=s.size(), l, r, count[N];
  bool dp[N][N];
  for(l=0; l<N; l++) {
    dp[l][l] = true;
  }
  for(l=N-1; l>=0; l--) {
    for(r=l+1; r<N; r++) {
      dp[l][r] = false;
      if(s[l] == s[r]) {
        if(l+1==r || dp[l+1][r-1]) {
          dp[l][r] = true;
        }
      }
    }
  }
  for(l=N-1; l>=0; l--) {
    count[l] = N;
    for(r=N-1; r>=l; r--) {
      if(dp[l][r]) {
        count[l] = (r==N-1) ? 0 : min(count[l], 1+count[r+1]);
      }
    }
  }
  return count[0];
}

int main(void ) {
  string s("abdbca");
  cout<<partition(s)<<'\n';

  s = "cddpd";
  cout<<partition(s)<<'\n';

  s = "cdpdd";
  cout<<partition(s)<<'\n';

  s = "pqr";
  cout<<partition(s)<<'\n';

  s = "pp";
  cout<<partition(s)<<'\n';

  s = "madam";
  cout<<partition(s)<<'\n';

  return 0;
}