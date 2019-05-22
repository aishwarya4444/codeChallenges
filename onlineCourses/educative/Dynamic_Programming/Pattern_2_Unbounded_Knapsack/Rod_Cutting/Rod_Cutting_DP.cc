// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5729201025974272

#include<iostream>
#include<vector>
using namespace std;

int cutRod(vector<int> &L, vector<int> &P, int length) {
  int i, l, profit1, profit2;
  int dp[L.size()][length+1];

  // for length=0 there's no profit
  for(i=0; i<L.size(); i++) {
    dp[i][0] = 0;
  }

  for(l=1; l<=length; l++) {
    if(length>=L[0]) {
      dp[0][l] = P[0];
    }
  }

  for(i=1; i<L.size(); i++) {
    for(l=1; l<=length; l++) {
      profit1 = 0;
      profit2 = 0;
      if(l>=L[i]) {
        profit1 = P[i] + dp[i][l-L[i]];
      }
      profit2 = dp[i-1][l];
      dp[i][l] = max(profit2, profit1);
    }
  }

  return dp[L.size()-1][length];
}

int main(void) {
  vector<int> lengths, prices;
  int rodLength;

  // rod lengths
  lengths.push_back(1);
  lengths.push_back(2);
  lengths.push_back(3);
  lengths.push_back(4);
  lengths.push_back(5);

  // prices
  prices.push_back(2);
  prices.push_back(6);
  prices.push_back(7);
  prices.push_back(10);
  prices.push_back(13);

  // rodLength
  rodLength = 5;

  cout<<cutRod(lengths, prices, rodLength)<<'\n';

  return 0;
}