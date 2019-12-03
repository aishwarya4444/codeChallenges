// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5665054615666688

#include<iostream>
#include<cstring>
using namespace std;

int editDist(string s, string t) {
  int r, c, R=s.size(), C=t.size();
  int dp[R+1][C+1];
  for(r=0; r<=R; r++) {
    dp[r][0] = r;
  }
  for(c=0; c<=C; c++) {
    dp[0][c] = c;
  }
  for(r=1; r<=R; r++) {
    for(c=1; c<=C; c++) {
      if(s[r-1]==t[c-1]) {
        dp[r][c] = dp[r-1][c-1];
      } else {
        dp[r][c] = 1 + min(dp[r-1][c-1], min(dp[r-1][c], dp[r][c-1]));
      }
    }
  }
  return dp[R][C];
}

int main(void) {
  cout<<editDist("bat", "but")<<endl;
  cout<<editDist("abdca", "cbda")<<endl;
  cout<<editDist("passpot", "ppsspqrt")<<endl;
}