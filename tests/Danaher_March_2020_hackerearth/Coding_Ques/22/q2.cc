#include<iostream>
#include<cstring>
#include<vector>
#define MOD 1000000007
#define LLI long long int
using namespace std;

int T, K;
long int r, c, num, N;
LLI ways;
vector<long int> nums;
vector<vector<LLI> > dp;

void solve(long int i, long int count, LLI prod, LLI &ways) {
  if(count == 0) {
    ways = (ways + prod)%MOD;
    return;
  }

  if(i==N) {
    return;
  }

//  if(dp[i][count] != 0) {
//    return;
//  }

  // include
  solve(i+1, count-1, prod*nums[i], ways);
  // don't include
  solve(i+1, count, prod, ways);

//  dp[i][count] = ways;
}

void printMatrix() {
  for(r=0; r<N; r++) {
    for(c=0; c<=K; c++) {
      cout<<dp[r][c]<<' ';
    }
    cout<<endl;
  }
}

int main() {
  cin>>T;

  while(T--) {
    cin>>N>>K;
    nums.clear();
    dp.clear();
    dp = vector<vector<LLI> >(N+1, vector<LLI>(K+1, 0));

    while(N--) {
      cin>>num;
      nums.push_back(num);
    }

    N = nums.size();
    if(K>N) {
      cout<<0<<endl;
      continue;
    }

    ways = 0;
    solve(0, K, 1, ways);
//    printMatrix();
    cout<<ways<<endl;
  }

  return 0;
}

/*
1
4 3
1 1 2 1
*/
