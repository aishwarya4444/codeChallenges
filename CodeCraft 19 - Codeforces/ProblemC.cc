// http://codeforces.com/contest/1111/problem/C

#include<iostream>
#include<vector>
#include<cmath>
#define ULLI unsigned long long int
using namespace std;

int n, k, A, B, i, avenger, lb, ub;
vector<bool> position(1073741825, false);

bool isAnyTrue(ULLI l, ULLI r) {
  while(l<=r) {
    if(position[l]) {
      return true;
    }
    l++;
  }
  return false;
}

void solve(ULLI lb, ULLI ub, ULLI &result) {
  if(isAnyTrue(lb, ub)) {
    if(lb==ub) {
      result += B;
    } else {
      solve(lb, (lb+ub)>>1, result);
      solve(1+((lb+ub)>>1), ub, result);
    }
  } else {
    result += A;
  }
}

int main(void ) {
  ULLI lb, ub;
  ULLI result=0;
  cin>>n>>k>>A>>B;
  for(i=0; i<k; i++) {
    cin>>avenger;
    position[avenger] = true;
  }
  lb=1;
  ub=pow(2, n);
  solve(lb, ub, result);
  cout<<result<<'\n';
  return 0;
}
