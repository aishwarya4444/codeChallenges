/*
https://www.spoj.com/problems/GNYR09F/
https://youtu.be/JrLXLSLC7t4?t=1055
https://github.com/singhsanket143/CppCompetitiveRepository/blob/master/CompetitiveProgramming/DynamicProgramming/AdjacentBitCount.cpp
*/

#include <bits/stdc++.h>
using namespace std;

int dp[101][101][2];

int solve(int n, int k, int curr) {
  if(n==0) return k==0;
  if(k<0) return 0;

  if(dp[n][k][curr] != -1) {
    return dp[n][k][curr];
  }

  int ans = 0;

  if(curr) {
    ans = solve(n-1, k-1, 1) + solve(n-1, k, 0);
  } else {
    ans = solve(n-1, k, 1) + solve(n-1, k, 0);
  }

  return dp[n][k][curr] = ans;
}

int main(){

  int t;
  cin>>t;

  while(t--) {
    int num, n, k;
    cin>>num>>n>>k;
    memset(dp, -1, sizeof dp);

    // fix :: 1 at start [n-1 bits remain] + 0 at start [n-1 bits remain]
    cout<<num<<' '<<solve(n-1, k, 1)+solve(n-1, k, 0)<<endl;
  }

  return 0;
}
