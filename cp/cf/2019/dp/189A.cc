/*
https://codeforces.com/problemset/problem/189/A
*/

#include<iostream>
#include<vector>
using namespace std;
int main() {
  int n, a, b, c;
  vector<int> dp, lengths;

  cin>>n>>a>>b>>c;
  dp = vector<int>(n+1, INT_MIN);
  lengths = vector<int>{a, b, c};

  dp[0] = 0;

  for(auto len: lengths) {
    for(int l=len; l<=n; l++) {
      dp[l] = max(dp[l], 1+dp[l-len]);
    }
  }

  cout<<dp[n]<<endl;

  return 0;
}
