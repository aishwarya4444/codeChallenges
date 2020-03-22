// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5707648880082944

#include<iostream>
#include<vector>
using namespace std;

int coinChange(vector<int> &C, int amount) {
  int dp[C.size()][amount];
  int i, a, ways1, ways2;

  // for 0 amount there's 1 way
  for(i=0; i<C.size(); i++) {
    dp[i][0] = 1;
  }

  for(i=0; i<C.size(); i++) {
    for(a=1; a<=amount; a++) {
      ways1 = 0;
      ways2 = 0;
      if(a>=C[i]) {
        ways1 = dp[i][a-C[i]];
      }
      if(i>0) {
        ways2 = dp[i-1][a];
      }
      dp[i][a] = ways1+ways2;
    }
  }

  return dp[C.size()-1][amount];
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

  return 0;
}