/*
https://codeforces.com/problemset/problem/455/A
*/

#include<iostream>
#include<vector>
using namespace std;

int main() {
  int n, N, num, maxLen = 1;
  vector<int> nums, dp;

  cin>>N;
  dp = vector<int>(N+1, 0);

  while(N--) {
    cin>>num;
    nums.push_back(num);
  }

  N=nums.size();
  dp[1] = nums[0];
  for(n=2; n<=N; n++) {
    dp[n] = max(dp[n-1], dp[n-2]+nums[n-1]);
  }

  cout<<dp[N]<<endl;
  return 0;
}
