// http://codeforces.com/contest/1111/problem/B

#include<iostream>
#include<vector>
#include<algorithm>
#define ULLI unsigned long long int
using namespace std;

ULLI n, k, m;
vector<int> avengers;

double calcAvg() {
  int i, N=avengers.size();
  ULLI sum=0;
  for(i=0;i<N;i++) {
    sum+=avengers[i];
  }
  return sum/N;
}

void solve() {
  double avg1, avg2;
  if(avengers.size()==1) {
    while(m--) {

    }
  }
  while(m--) {
    avg1 = 1.0 + calcAvg();
    avengers.erase(avengers.begin());
    avg2 = calcAvg();
  }
}

int main(void ) {
  ULLI i, avenger;
  cin>>n>>k>>m;
  for(i=0;i<n;i++) {
    cin>>avenger;
    avengers.push(avenger);
  }
  sort(avengers.begin(), avengers.end());
  solve();

  return 0;
}
