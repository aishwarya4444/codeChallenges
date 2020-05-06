// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5717424225648640

#include<iostream>
#include<vector>
using namespace std;

int minFee(vector<int> &fee) {
  vector<int> dp(fee.size()+1);

  dp[0] = 0;
  dp[1] = fee[0];
  dp[2] = fee[0];

  for(int i=3; i<=fee.size(); i++) {
    dp[i] = min(fee[i-1]+dp[i-1], min(fee[i-2]+dp[i-2], fee[i-3]+dp[i-3]));
  }

  return dp[fee.size()];
}

int main(void ) {
  vector<int> fee;

  // fee
  fee.push_back(1);
  fee.push_back(2);
  fee.push_back(5);
  fee.push_back(2);
  fee.push_back(1);
  fee.push_back(2);

  cout<<minFee(fee)<<'\n';

  // fee
  fee.clear();
  fee.push_back(2);
  fee.push_back(3);
  fee.push_back(4);
  fee.push_back(5);

  cout<<minFee(fee)<<'\n';

  return 0;
}
