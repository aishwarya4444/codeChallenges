// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5695872079757312

#include<iostream>
#include<vector>
using namespace std;

int getDiff(vector<int> &num) {
  int sum=0, sum1, sum2, i, s, N=num.size();

  for(i=0; i<N; i++) {
    sum += num[i];
  }

  bool dp[N][sum/2+1];

  for(i=0; i<N; i++) {
    dp[i][0] = true;
  }

  for(s=1; s<=sum/2; s++) {
    dp[0][s] = s==num[0];
  }

  for(i=1; i<N; i++) {
    for(s=1; s<=sum/2; s++) {
      dp[i][s] = false;
      if(dp[i-1][s]) {
        dp[i][s] = true;
      } else if(num[i]<=s) {
        dp[i][s] = dp[i-1][s-num[i]];
      }
    }
  }

  for(s=0; s<=sum/2; s++) {
    if(dp[N-1][s]) {
      sum1 = s;
    }
  }

  sum2 = sum-sum1;

  return sum1>sum2 ? sum1-sum2 : sum2-sum1;

}

int main(void) {
  vector<int> num;

  // Numbers
  num.push_back(1);
  num.push_back(3);
  num.push_back(100);
  num.push_back(4);

  cout<<getDiff(num);

  return 0;
}