// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5668753656250368

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int coinChange(vector<int> &C, int amount) {
  int dp[C.size()][amount+1];
  int i, a, minCoins1, minCoins2;

  // for 0 amount 0 coins are needed
  for(i=0;i<C.size(); i++) {
    dp[i][0] = 0;
  }

  for(i=0; i<C.size(); i++) {
    for(a=1; a<=amount; a++) {
      minCoins1 = INT_MAX;
      minCoins2 = INT_MAX;
      if(C[i]<=a) {
        minCoins1 = dp[i][a-C[i]];
        if(minCoins1!=INT_MAX) {
          minCoins1++;
        }
      }
      if(i>0) {
        minCoins2 = dp[i-1][a];
      }
      dp[i][a] = min(minCoins1, minCoins2);
    }
  }

  return dp[C.size()-1][amount]==INT_MAX ? -1 : dp[C.size()-1][amount];
}

int main(void) {
  int amount;
  vector<int> coins;

  // coins
  coins.push_back(1);
  coins.push_back(2);
  coins.push_back(3);

  // amount
  amount = 5;
  cout<<coinChange(coins, amount)<<'\n';
  cout<<coinChange(coins, 11)<<'\n';
  cout<<coinChange(coins, 7)<<'\n';

  // coins
  coins.clear();
  coins.push_back(3);
  coins.push_back(5);

  // amount
  amount = 7;

  cout<<coinChange(coins, amount)<<'\n';

  return 0;
}