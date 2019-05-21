// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5704980631650304

#include<iostream>
#include<cstring>
using namespace std;

void transform(string s1, string s2) {
  int N1=s1.size(), N2=s2.size(), i, j;
  int dp[N1+1][N2+1], length=0;
  for(i=0; i<=N1; i++) {
    dp[i][0] = 0;
  }
  for(j=0; j<=N2; j++) {
    dp[0][j] = 0;
  }
  for(i=1; i<=N1; i++) {
    for(j=1; j<=N2; j++) {
      dp[i][j] = 0;
      if(s1[i-1] == s2[j-1]) {
        dp[i][j] = 1+dp[i-1][j-1];
      } else {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
      length = max(length, dp[i][j]);
    }
  }
  cout<<"------------------\n";
  cout<<s1<<' '<<s2<<'\n';
  cout<<"Deletions: "<<s1.size()-length<<'\n';
  cout<<"Insertions: "<<s2.size()-length<<'\n';
}

int main(void) {
  transform("abc", "fbc");
  transform("abdca", "cbda");
  transform("passport", "ppsspt");
  return 0;
}
