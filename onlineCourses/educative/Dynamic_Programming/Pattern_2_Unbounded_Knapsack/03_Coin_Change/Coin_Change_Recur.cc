// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5707648880082944

#include<iostream>
#include<vector>
using namespace std;

int coinChange(int i, vector<int> &C, int amount) {
  if(i==C.size()) {
    return 0;
  }
  if(amount==0) {
    return 1;
  }
  int ways1=0, ways2=0;
  if(amount>=C[i]) {
    ways1 = coinChange(i, C, amount-C[i]);
  }
  ways2 = coinChange(i+1, C, amount);
  return ways1+ways2;
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

  cout<<coinChange(0, coins, amount)<<'\n';

  return 0;
}