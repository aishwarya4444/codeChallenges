// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5745865499082752

#include<iostream>
#include<vector>
using namespace std;

int calculateProfit(vector<int> &W, vector<int> &P, int i, int C) {
  if(i==W.size()) {
    return 0;
  }
  int leftProfit=0, rightProfit=0;
  if(C-W[i]>=0) {
    leftProfit = P[i] + calculateProfit(W, P, i, C-W[i]);
  }
  rightProfit = calculateProfit(W, P, i+1, C);
  return max(leftProfit, rightProfit);
}

int main(void) {
  vector<int> weights, profits;
  int capacity, profit;

  // Weights
  weights.push_back(1);
  weights.push_back(3);
  weights.push_back(4);
  weights.push_back(5);

  // Profits
  profits.push_back(15);
  profits.push_back(50);
  profits.push_back(60);
  profits.push_back(90);

  // Capacity
  capacity = 8;

  profit = calculateProfit(weights, profits, 0, capacity);

  cout<<profit<<'\n';

  // Capacity
  capacity = 6;

  profit = calculateProfit(weights, profits, 0, capacity);

  cout<<profit<<'\n';

  return 0;
}