// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5676982813589504

#include<iostream>
#include<vector>
using namespace std;

/*
https://leetcode.com/problems/house-robber/
https://leetcode.com/problems/house-robber-ii/
https://leetcode.com/problems/house-robber-iii/
*/

int solve(vector<int> &house) {
  int N=house.size(), i;
  int dp[N+1];
  dp[0] = 0;
  dp[1] = house[0];
  for(i=2; i<=N; i++) {
    dp[i] = max(dp[i-1], house[i-2]+dp[i-1]);
  }
  return dp[N];
}

int main(void) {
  vector<int> house;

  // wealth in houses
  house.push_back(2);
  house.push_back(5);
  house.push_back(1);
  house.push_back(3);
  house.push_back(6);
  house.push_back(2);
  house.push_back(4);
  cout<<solve(house)<<'\n';

  // wealth in houses
  house.clear();
  house.push_back(2);
  house.push_back(10);
  house.push_back(14);
  house.push_back(8);
  house.push_back(1);
  cout<<solve(house)<<'\n';
}