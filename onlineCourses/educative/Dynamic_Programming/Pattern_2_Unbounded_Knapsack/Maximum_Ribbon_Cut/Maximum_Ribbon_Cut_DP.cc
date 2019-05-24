// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5709198289534976

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int ribbonCut(vector<int> &R, int length) {
  int l, i, numCut1, numCut2;
  int dp[R.size()][length+1];

  // for 0 length we need 0 cuts
  for(i=0; i<R.size(); i++) {
    dp[i][0] = 0;
  }

  for(i=0; i<R.size(); i++) {
    for(l=1; l<=length; l++) {
      numCut1 = INT_MIN;
      numCut2 = INT_MIN;
      if(l>=R[i]) {
        numCut1 = dp[i][l-R[i]];
        if(numCut1 != INT_MIN) {
          numCut1++;
        }
      }
      if(i>0) {
        numCut2 = dp[i-1][l];
      }
      dp[i][l] = max(numCut1, numCut2);
    }
  }

  return dp[R.size()-1][length] == INT_MIN ? -1 : dp[R.size()-1][length];
}

int main(void) {
  int length;
  vector<int> ribbons;

  // ribbons
  ribbons.push_back(2);
  ribbons.push_back(3);
  ribbons.push_back(5);

  // length
  length = 5;
  cout<<ribbonCut(ribbons, length)<<'\n';


  // ribbons
  ribbons.clear();
  ribbons.push_back(2);
  ribbons.push_back(3);

  // length
  length = 7;
  cout<<ribbonCut(ribbons, length)<<'\n';

  // ribbons
  ribbons.clear();
  ribbons.push_back(3);
  ribbons.push_back(5);
  ribbons.push_back(7);

  // length
  length = 13;
  cout<<ribbonCut(ribbons, length)<<'\n';

  // ribbons
  ribbons.clear();
  ribbons.push_back(3);
  ribbons.push_back(5);

  // length
  length = 7;
  cout<<ribbonCut(ribbons, length)<<'\n';

  return 0;
}