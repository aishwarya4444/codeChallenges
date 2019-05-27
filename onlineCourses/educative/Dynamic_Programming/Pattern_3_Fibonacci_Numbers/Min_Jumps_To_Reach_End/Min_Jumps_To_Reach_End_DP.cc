// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5685057352105984

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int minJumps(vector<int> &J) {
  int i, j, N=J.size();
  vector<int> dp(N, INT_MAX);
  dp[0] = 0;
  for(i=0; i<N-1; i++) {
    for(j=i+1; j<=i+J[i] && j<N; j++) {
      dp[j] = min(dp[j], dp[i]+1);
    }
  }
  return dp[N-1];
}

int main(void ) {
  vector<int> jumps;

  // jumps
  jumps.push_back(2);
  jumps.push_back(1);
  jumps.push_back(1);
  jumps.push_back(1);
  jumps.push_back(4);

  cout<<minJumps(jumps)<<'\n';

  // jumps
  jumps.clear();
  jumps.push_back(1);
  jumps.push_back(1);
  jumps.push_back(3);
  jumps.push_back(6);
  jumps.push_back(9);
  jumps.push_back(3);
  jumps.push_back(0);
  jumps.push_back(1);
  jumps.push_back(3);

  cout<<minJumps(jumps)<<'\n';
  return 0;
}