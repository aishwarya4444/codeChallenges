// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5681461390737408

#include<iostream>
#include<vector>
using namespace std;

void sorted_lis(vector<int> &v) {
  int N=v.size(), i, j, length=v.size()?1:0;
  int dp[N];
  dp[0]=1;
  for(i=1; i<N; i++) {
    dp[i]=1;;
    for(j=0; j<i; j++) {
      if(v[i]>v[j] && dp[i]<dp[j]+1) {
        dp[i] = dp[j] + 1;
        length = max(length, dp[i]);
      }
    }
  }
  cout<<N-length<<'\n';
}

int main(void) {
  vector<int> v;

  // [ 4, 2, 3, 6, 10, 1, 12 ]
  v.push_back(4);
  v.push_back(2);
  v.push_back(3);
  v.push_back(6);
  v.push_back(10);
  v.push_back(1);
  v.push_back(12);
  sorted_lis(v);

  // [ -4, 10, 3, 7, 15 ]
  v.clear();
  v.push_back(-4);
  v.push_back(10);
  v.push_back(3);
  v.push_back(7);
  v.push_back(15);
  sorted_lis(v);

  // [ 3, 2, 1, 0 ]
  v.clear();
  v.push_back(3);
  v.push_back(2);
  v.push_back(1);
  v.push_back(0);
  sorted_lis(v);

  return 0;
}
