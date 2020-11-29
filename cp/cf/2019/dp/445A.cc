/*
https://codeforces.com/problemset/problem/445/A
*/

#include<iostream>
#include<vector>
using namespace std;

vector<long long> a;
int N, maxN=100001;

int main() {
  int n, num;
  cin>>N;
  a = vector<long long> (maxN, 0);
  for(n=0; n<N; n++) {
    cin>>num;
    a[num]++;
  }
  for(n=2; n<maxN; n++) {
    a[n] = max(a[n-1], n*a[n]+a[n-2]);
  }
  cout<<a[maxN-1]<<endl;
  return 0;
}
