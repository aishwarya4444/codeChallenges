/*
https://codeforces.com/problemset/problem/313/B
*/

#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int main() {
  vector<int> dp(100001, 0);
  int n=1, l, r, Q;
  string str;

  cin>>str;
  str = '_'+str;

  for(n=1; n<str.size(); n++) {
    dp[n] = str[n]==str[n-1] ? 1+dp[n-1] : dp[n-1];
  }

  cin>>Q;
  while(Q--) {
    cin>>l>>r;
    cout<<dp[r]-dp[l]<<endl;
  }

  return 0;
}
