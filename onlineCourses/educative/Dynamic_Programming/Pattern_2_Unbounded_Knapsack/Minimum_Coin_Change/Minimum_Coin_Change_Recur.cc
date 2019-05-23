// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5668753656250368

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int coinChange(int i, vector<int> &C, int amount) {
  if(i==C.size()) {
    return INT_MAX;
  }
  if(amount==0) {
    return 0;
  }
  int numCoins1=INT_MAX, numCoins2=0;
  if(amount>=C[i]) {
    numCoins1 = coinChange(i, C, amount-C[i]);
    if(numCoins1!=INT_MAX) {
      numCoins1++;
    }
  }
  numCoins2 = coinChange(i+1, C, amount);
  return min(numCoins1, numCoins2);
}

int coinChange(vector<int> &C, int amount) {
  int minCoins = coinChange(0, C, amount);
  return minCoins==INT_MAX ? -1 : minCoins;
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